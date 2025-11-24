# PA5 - Web Server

**Due Thursday, December 4, 11:59PM**

Github Classroom Assignment: <https://classroom.github.com/a/hlq9KJbK>

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

The requests the chat server listens for are described in this section

### /chats

A request to `/chats` responds with the plain text rendering of all the chats.

The rendered chat format is

```
[#N 20XX-MM-DD HH:MM] <username>: <message>
(<rusername>) <reaction>
... [more reactions] ...
... [more chats] ...
```

Chats must be rendered properly, as in PSet5. You can put in whatever effort you like into lining things up nicely within these constraints, but these are the requirements.

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

Here's another:

```
[#1 2024-10-24 13:01]        yash: hi all! react with 👍🏻 if you think the lab is good to go, or 😬 if you think it needs more testing
                          (aaron)  👍🏻
                          (elena)  😬
                         (arunan)  😬
                          (janet)  😬
                         (travis)  😬
                            (joe)  🐿️
[#2 2024-10-24 13:02]        yash: OK we'll go with what joe said
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

## Implementation Guide

This page is the entire _specification_ for the assignment; it's what you need to implement. You are free to make whatever choices you like in your code within these constraints. To help you on your way, we have an _implementation guide_:

- Make sure to do pset5 first if you haven't already! It will create helper functions you can use here.
- [HTTP](https://ucsd-cse29.github.io/fa25/pa/pa5/http-server.html)
- [Function-by-function Breakdown](https://ucsd-cse29.github.io/fa25/pa/pa5/data-vs-requests.html)
- [Representing Chats and Reactions](https://ucsd-cse29.github.io/fa25/pa/pa5/representations.html)
- [Other Useful Functions](https://ucsd-cse29.github.io/fa25/pa/pa5/helpful-functions.html)

## Handin

- Hand in your repository on Gradescope
- Make sure make chat-server builds your server (that's the command we will run), and the server runs on a predictable port with, for example, ./chat-server 8000
- Don't forget CREDITS.txt
- There are no hidden tests for this PA, so you can get immediate feedback on your code.
- There are no design questions for this PA.
- Make sure to keep following good coding practices, including comments and style.
