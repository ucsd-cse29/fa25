# PA5 - Web Server

**Due Thursday, December 4, 11:59PM**

Github Classroom Assignment: [https://classroom.github.com/a/0wvJcgvj](https://classroom.github.com/a/0wvJcgvj)

**Important**: there is no resubmission available for PA5. Plan your development and testing accordingly. We will also have no hidden tests for PA5 so that you can get immediate feedback on your code.

There are also no design questions for this PA.

## Web Servers and HTTP

[HTTP](https://en.wikipedia.org/wiki/HTTP) is one of the most common protocols for communicating across computers. At the systems programming level, this means using system calls (usually in C) to tell the operating system to send bytes over a network.

One nice feature of HTTP is that it is a primarily text-based protocol, which makes it more straightforward for humans to read and debug. It is also well-understood by web browsers and programs like `curl`, making it easy to test and connect to user-facing devices.

It's useful to get experience with the format of HTTP, and with using system calls in C to manipulate HTTP requests.

## Task – Chat Server

In this programming assignment, you'll write a C program to implement a chat room (think a plain-text version of [Slack](https://slack.com/) or [Discord](https://discord.com/)).

It's best to complete the PA on `ieng6`, because it gives a consistent testing environment for the live server.

Your programs should compile and run with:

```bash
make chat-server
./chat-server <optional port number>
```

The server should start with ./chat-server and print a single message:

```bash
$./chat-server
Server started on port PPPPP
```

If a port number was provided, it should use that port, otherwise it should print an open port that was selected.

It should continue running, listening for requests on that port, until shutdown with Ctrl-c. It can print any other logging messages or other output needed to the terminal.

The requests the chat server listens for are described in this section:

### /chats

A request to `/chats` responds with the plain text rendering of all the chats.

The rendered chat format is

```
[#N 20XX-MM-DD HH:MM] <username>: <message>
(<rusername>) <reaction>
... [more reactions] ...
... [more chats] ...
```

Chats must be rendered properly, as in HW5.5. You can put in whatever effort you like into lining things up nicely within these constraints, but these are the requirements.

Example chats rendering might look like:

```
[#1 2024-10-06 09:01]         joe: hi aaron
[#2 2024-10-06 09:02]       aaron: sup
[#3 2024-10-06 09:04]         joe: working on the example chat for the PA
[#4 2024-10-06 09:06]       aaron: oh cool what should it say
[#5 2024-10-06 09:07]         joe: I dunno we could go pretty meta with it? I pushed an example go check it out. like a chat about the chat
[#6 2024-10-06 09:10]       aaron: eh kinda lame tbh
[#7 2024-10-06 09:11]         joe: whatever I already wrote it, going with it as-is
[#8 2024-10-06 09:12]       aaron: ok but make sure we don't look like jerks
[#9 2024-10-06 09:12]       aaron: or at least not me
                            (joe)  👍🏻
[#10 2024-10-06 09:12]         joe: good talk
```

### /post

A `post` request looks like this:

`/post?user=<username>&message=<message>`

This creates a new chat with the given username and message string with a timestamp given by the time the request is received by the server. It must respond with the list of all chats (including the new one).

Limits and constraints:

- If a parameter (username or message) is missing, respond with some kind of error (HTTP code 400 or 500)
- If username is longer than 15 bytes, respond with some kind of error (HTTP code 400 or 500)
- If message is longer than 255 bytes, respond with some kind of error (HTTP code 400 or 500)
- If a post would make there be more than 100000 (one hundred thousand) chats, the server should respond with an error (HTTP code 404 or 500)

### /react

`/react?user=<username>&message=<reaction>&id=<id>`

Creates a _new reaction_ to a chat by the given username with the given message string, reacting to the post with the given id (the ids are the `#N` at the beginning of posts). It must respond with the list of all chats (including the new one).

Limits and constraints:

- If the id is not the ID of some existing chat, respond with some kind of error (HTTP code 400 or 500).
- If a parameter (username or message or id) is missing, respond with some kind of error (HTTP code 400 or 500)
- If username is longer than 15 bytes, respond with some kind of error (HTTP code 400 or 500)
- If message is longer than 15 bytes, respond with some kind of error (HTTP code 400 or 500) – reactions are intended to be short!
- If a reaction would make a chat have more than 100 reactions, the server should respond with an error (HTTP code 404 or 500)

## **Implementation Guide**

This page is the entire _specification_ for the assignment; it's what you need to implement. You are free to make whatever choices you like in your code within these constraints. To help you on your way, we have some _implementation notes_ below with suggestions and ideas for how to get started and what to think about. These are not requirements, just suggestions!

Make sure to do **Problem Set 5** first if you haven't already! It will create helper functions you can use as well as help you develop an understanding of your task.

## The `http-server` Library

We've provided you with `http-server.c` and `http-server.h`. This is code for
you to treat as a _library_, you shouldn't change it at all (though you may
learn from reading it!).

It provides one function for you to use:

```c
void start_server(void(*handler)(char*, int), int port);
```

This function takes two arguments: a `handler` that takes HTTP requests and
writes responses, and a `port` for telling the server what address to use. The
`port` can be `0` to ask the operating system to choose one for us.

The type for `handler` is the type of a _function pointer_, which is the address
of a function. To use `start_server`, we define a function (it can have any
name) with the appropriate signature and pass it into `start_server` as an
argument. The `handler` function takes two arguments:

```c
void(*handler)(char*, int)
```

- The first, the `char*`, is a string containing the request from the internet.
  It will be an HTTP request.
- The second, the `int`, is a _file descriptor_ that our program can use to
  write a response using the `write` or `send` system call

Here's a straightforward example that just responds to the user with a constant string:

```c
#include "http-server.h" // http-server includes a lot of other useful things
char const* HTTP_200_OK = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n";
void handle_response(char *request, int client_socket) {
    printf("The user sent a request with: %s\n", request);
    write(client_socket, HTTP_200_OK, strlen(HTTP_200_OK));
    write(client_socket, "Hello!", 6);
}
int main() {
    start_server(&handle_response, 0);
}
```

```bash
$ gcc -o print-request print-request.c http-server.c
$ ./print-request
Server started on port PPPPP (will be a specific number for you)
# the lines below print *when the request is received*
The user sent a request with: GET /post?user=joe&message=hi HTTP/1.1
Host: localhost:36611
User-Agent: curl/7.68.0
Accept: */*
The user sent a request with: GET /post?user=aaron&message=sup HTTP/1.1
Host: localhost:36611
User-Agent: curl/7.68.0
Accept: */*
```

(in another terminal)

```bash
$ curl "http://localhost:PPPPP/post?user=joe&message=hi"
Hello!
$ curl "http://localhost:PPPPP/post?user=aaron&message=sup"
Hello!
```

Then, every time the server gets a request, it will call the `handle_request`
function, which will print the contents of the request, and then use the `write` or `send` system call to send a response back to the client (in this case with a constant string). This is the entry point to our program, and it's a good starting point for you to build up from!

One other tip for using `start_server`:

- If `port` is 0, the library will pick an open port provided by the operating
  system. This is convenient for getting started
- However, when you restart a program it's annoying to have to change the port
  number in any requests you have in your bash history, etc. So you can also
  provide the port number as an argument, which could be hardcoded or taken from a
  command-line argument. You can do that to re-run the program with the same port
  it used last time to keep your examples consistent

### HTTP Requests

The first argument to `handler` is a `char*` with a a reference to the HTTP
request. For our `chat-server`, all requests will be `GET` requests and will
look something like

```bash
GET /post?user=joe&message=hi HTTP/1.1
Host: localhost:36611 User-Agent:
curl/7.68.0 Accept: */ *
```

The string after `GET` is the path of the request, and that's the part that will
change depending on the type of request we get. Part of the job of the
`chat-server` will be to extract the relevant information from the path, like
which action to take (post, react, etc.) and the parameters of the action (user,
message, etc.) in order to work with them.

It probably makes sense to use some C string library functions to do this. In
particular `strtok` will allow you to “split up” a string by replacing
delimiters like ` `, `&`, and `=` with null terminators. You may also find
`strcspn`, `strstr`, or `strpbrk` useful; it's up to you to come up with a plan
to put these together to extract the information out of each request.

### HTTP Responses

The second argument to `handler` is an `int` that is a file descriptor for the
response. The `http-server` library has set things up so writing to the socket
sends bytes directly back to whatever client made the request.

The format of a HTTP response for a successful response is

```bash
HTTP/1.1 200 OK
Content-Type: text/plain

... response body ...
```

**Note**: A nuance of this is that the newlines in HTTP responses are not just
`\n`; [they are required to be
`\r\n`](https://en.wikipedia.org/wiki/HTTP_message_body) (which, interestingly,
is how line endings
work on Windows). Some software will work with just a `\n` for line breaks, but
the correct thing to do is use `\r\n`, so in a string literal the HTTP header above
would look like

```bash
"HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n...response body...
```

There are many other `Content-Type`s in the world other than `text/plain`! But
we will focus on just plain text reponses for this assignment.

## Working Incrementally: Data vs. Requests

One way to break down the work the server needs to do is:

- Parsing and interpreting requests (is the request a new post, a reaction, etc)
- Updating the current data (chats and reactions) based on the parameters in the request
- Responding to requests based on the current state of the data (chats and requests)

One way to work incrementally is to separate the _data handling_ and the
_request handling_ parts into different functions.

The _data handling_ functions can be tested with `assert`s, and the _request
handling_ can be tested with `curl` or a client.

We think the following functions might be useful for you to implement. In your
program you might have slightly different signatures or ideas, but these are a
useful starting point. Also, our staff is more familiar with this approach, so
it will take us less time to help you in office hours!

### Data Handling Functions

These functions can be written and tested without starting a server at all. You
could consider having a separate `main` function in its own file that just tests
these!

#### **`add_chat`**

A function `add_chat` can add a single chat.

```c
uint8_t add_chat(char* username, char* message)
```

This function might have several tasks:

1. Update the current `id`
2. Get the current timestamp
3. Create a new chat and fill in its username and message fields
4. As needed, allocate new space, put the new chat in heap memory, store a
   reference to it in an array, etc. depending on your specific representation of
   chats

This is testable by setting up initial states of chats and reactions, running
the function, and then using `assert` or `printf` on the results.

#### **`add_reaction`**

Similar to `add_chat`, this adds a single reaction:

```c
uint8_t add_reaction(char* username, char* message, char* id)
```

This function might have several tasks:

- Use the id to locate the chat that this reaction is for (and maybe return
  early with an error if the id is invalid/out of range)
- Create a new reaction and fill in its username and message fields
- Add the reaction to the chat struct somehow, maybe with newly allocated space,
  an added element or reference in an array, etc. depending on your specific representation of chats and reactions
- Update the count of reactions on the referenced chat

This is testable by setting up initial states of chats and reactions, running
the function, and then using `assert` or `printf` on the results.

### Request and Response Handling Functions

You will definitely need to write a function for handling responses. But the
work of handling individual responses can be broken up. One approach could be to
get the path and query parameter string from the request and check if it's path
is `/post`, `/chats`, etc, then pass the string to other functions

#### **`respond_with_chats`**

```c
void respond_with_chats(int client)
```

This function is reponsible for using `write` or `send` to send the response to
the client that made the request. It might include:

- Using `snprintf` to format strings with data from the timestamp or ids
- Calling `write(client, str, size)` on various strings (with the appropirate size) to directly send the data to the client

#### **`handle_post`**

```c
// path is a string like "/post?user=joe&message=hi"
void handle_post(char* path, int client)
```

This function can have several tasks:

- Use string functions to extract the username and message from the path
- Call `add_chat` to do the data update
- Call `respond_with_chats` to send the response

#### **`handle_reaction`**

```c
// path is a string like "/react?user=joe&message=hi&id=3"
void handle_reaction(char* path, int client)
```

This function can have several tasks:

- Use string functions to extract the username, message, and id from the path
- Call `add_reaction` to do the data update
- Call `respond_with_chats` to send the response

## Representing Chats and Reactions

Chats and reactions both have multiple fields, so a natural choice is to
represent both chats and reactions as structs.

A chat has several components, which may be good candidates for struct fields:

- The message
- The username
- The timestamp
- The reactions to the message

A reaction has the message content and the user who posted it (no timestamp or
reactions-to-reactions), both of which are fixed-size.

You could consider structures like these; what are some tradeoffs? (We've
assumed that the program defines some useful constants to avoid repeating
specific numbers).

```c
struct Reaction {
    char user[USERNAME_SIZE];
    char message[REACTION_SIZE];
}
struct Chat {
    uint32_t id;
    char user[USERNAME_SIZE];
    char message[MESSAGE_SIZE];
    char timestamp[TIMESTAMP_SIZE];
    uint32_t num_reactions;
    Reaction reactions[MAX_REACTIONS];
}
```

```c
struct Reaction {
    char *user;
    char *message;
}
struct Chat {
    uint32_t id;
    char *user;
    char *message;
    char *timestamp;
    uint32_t num_reactions;
    Reaction *reactions;
}
```

These are ideas – some combination of them might work, and they are not necessarily perfect or complete. Some things to think about:

- Which fields are fixed-size?
- Which fields can grow?
- Which fields can change?
- What are limits for them described in the specification?

## Other Helpful Functions

This PA explores several features that are straightforward to use, but there are _many_ of them. We might add more to this list as the PA goes on! Here are a few functions you'll probably find useful; try `man` on them, or follow the links, or do your own searching and research. Don't forget all the functions from class (e.g. `malloc` and other allocation functions, `strstr` and other string manipulation functions, and so on). This list is mainly focused on things we haven't tried in class.

- [`atoi`](https://cplusplus.com/reference/cstdlib/atoi/?kw=atoi): convert `char*` to integer

- **Time functions:**

  - [`time`](https://en.cppreference.com/w/c/chrono/time): get the current time
  - [`localtime`](https://en.cppreference.com/w/c/chrono/localtime): convert the time to the current local time zone
  - [`strftime`](https://en.cppreference.com/w/c/chrono/strftime): print the time in a given format

## Handin

- Hand in your repository on Gradescope
- Make sure make chat-server builds your server (that's the command we will run), and the server runs on a predictable port with, for example, ./chat-server 8000
- Don't forget CREDITS.txt
- There are no hidden tests for this PA, so you can get immediate feedback on your code.
- There are no design questions for this PA.
- Make sure to keep following good coding practices, including comments and style.
