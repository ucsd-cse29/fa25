# PA2 - Hashing and Passwords: Due 10/23 at 11:59pm - [Github Classroom Link](https://classroom.github.com/a/DK5n-VdM)

[Cryptographic hash functions](https://en.wikipedia.org/wiki/Cryptographic_hash_function) take an input of arbitrary length and produces a fixed length output. The special features are that the outputs are _deterministic_ (the same input always generates the same output) and yet the outputs are apparently “random” – two similar inputs are likely to produce very different outputs, and it's difficult to determine the input by looking at the ouput.

A common application of hashing is in storing passwords. Many systems store only the hash of a user's password along with their username. This ensures that even if someone gains access to the stored data, users' actual passwords are not exposed. When a user types in a password on such a system, the password handling software grants access if the hash value generated from the user's entry matches the hash stored in the password database.

We said above that it is _difficult_ to determine an input given an output. [Password cracking](https://en.wikipedia.org/wiki/Password_cracking) is a family of techniques for accomplishing this difficult (but possible!) task.
That is, let's say we have access to a user's password _hash_ only. Can we figure out their password? We could then use it to log in, and it may also be shared across their accounts which we could also access.

In some cases, password cracking can [exploit the structure](https://en.wikipedia.org/wiki/MD5#Security) of a hash function; this is a topic for a cryptography class. In our case, we will take a more brute-force approach: trying variations on existing known passwords, under the assumption that [many passwords are easy to guess](https://en.wikipedia.org/wiki/List_of_the_most_common_passwords).

## Getting Started

To get started, visit the [Github Classroom](https://classroom.github.com/a/DK5n-VdM) assignment link. Select your username from the list (or if you don't see it, you can skip and use your Github username). A repository will be created for you to use for your work. This PA should be completed on the `ieng6` server. Refer [this](https://ucsd-cse29.github.io/fa25/week1/lab1.html#logging-into-ieng6) section in Week 1's Lab for instructions on logging in to your account on `ieng6` and working with files on the server.

**Note** - The autograder uses the C11 standard of the C programming language.

## Overall Task

We'll start by describing the overall task and goal so it's clear where you're going.
However, don't start by trying to implement this exactly – use the milestones below to get there.

### `pwcrack`, a Password Cracker

Write a program `pwcrack` that takes one command-line argument, the `SHA256` hash of a password in hex format.

The program then reads from `stdin` potential passwords, one per line (assumed to be in UTF-8 format).

The program should, for each password:

- Check if the SHA256 hash of the potential password matches the given hash
- Check if the SHA256 hash of the potential password with each of its ASCII characters
  uppercased or lowercased matches the given hash

If a matching password is found, the program should print

```
Found password: SHA256(<matching password>) = <hash>
```

If a matching password is _not_ found, the program should print:

```
Did not find a matching password
```

### Examples

`seCret` has a SHA256 hash of `a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd`, and `notinlist`
has a SHA256 hash of `21d3162352fdd45e05d052398c1ddb2ca5e9fc0a13e534f3c183f9f5b2f4a041`

```
$ ./pwcrack a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
Password
NeverGuessMe!!
secret
Found password: SHA256(seCret) = a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
$ ./pwcrack 21d3162352fdd45e05d052398c1ddb2ca5e9fc0a13e534f3c183f9f5b2f4a041
Password
NeverGuessMe!!
secret
<Press Ctrl-D for end of input>
Did not find a matching password
```

We could also put the potential passwords in a file:

```
$ cat guesses.txt
Password
NeverGuessMe!!
secret
$ ./pwcrack a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd < guesses.txt
Found password: SHA256(seCret) = a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
```

Note that we only consider single-character changes when trying
uppercase/lowercase variants of the guesses (i.e. we DON'T try all possible
capitalizations of the string): In the example below, the correct password is
NOT found because going from `SECRET` to `seCret` would require 5 characters to be changed.

```
$ ./pwcrack a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
SECRET
<Press Ctrl-D for end of input>
Did not find a matching password
```

## Useful Tools

You will be using [`openssl`](https://docs.openssl.org/3.1/man3/SHA256_Init) library for this PA. This requires an extra argument for compiling your code:

```
gcc <your .c file> -o <output name> -lcrypto
```

The relevant function from that library is `SHA256`. You can follow the link above to see its official type; in terms we've been using in class its type is:

``` c
SHA256(const unsigned char data[], uint64_t count, unsigned char md_buf[]);
```

The `data` parameter is _not_ assumed to be a C string. That is, it may or may not be null terminated, `SHA256` won't check. The hash function will operate on however many bytes are specified by `count`. So, if passing a C string, the caller of `SHA256` is responsible for using something like `strlen` to calculate `count` and provide it.
The `md_buf` argument is where the hash gets stored, and it is assumed to be at least 32 bytes long (SHA256 has a fixed output size which is 32 bytes (256 bits)).

Here's a short code snippet that shows how to use it:

``` c
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <openssl/sha.h>

const int SHA_LENGTH = 32;

int main(int argc, char** argv) {
    uint8_t i = 0;
    // SHA256 hashes are always 32 bytes long (independent of input length)
    unsigned char hash[SHA_LENGTH];
    // argv[1] is the first command-line argument as a C string
    SHA256(argv[1], strlen(argv[1]), hash); // result stored in hash
    for(i = 0; i < SHA_LENGTH; i += 1) {
        printf("%02x", hash[i]); // %02x means print as a 2-digit hex value
    }
    printf("\n");
    for(i = 0; i < SHA_LENGTH; i += 1) {
        printf("%d ", hash[i]);
    }
    printf("\n");
}
```

Example:

```
[cs29fa24@ieng6-201]:~:201$ gcc sha256.c -o sha256 -lcrypto
[cs29fa24@ieng6-201]:~:204$ ./sha256 seCret
a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
162 195 176 44 178 42 248 61 109 30 173 29 78 24 217 22 89 155 231 194 239 47 1 113 105 50 125 241 247 200 68 253
```

If you want to calculate a sha256 hash yourself you can use that program, there's also a command-line program called `openssl` that can do this from standard input:

```
[cs29fa24@ieng6-201]:~:203$ echo -n seCret | openssl dgst -sha256
(stdin)= a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
```

This also generates a SHA256 hash string of `seCret`. Note that both examples show 64 characters of hex values. 2 hex characters are used to represent one byte, so 64 hex characters are used to represent 32 bytes. (The `-n` argument to `echo` means “don't add a newline.” Without this, we'd get the hash of `seCret\n`)

## Using the Problem Set for your PA

Most of the needed functionality for the PA is in the problem set problems! So part of your workflow for this PA should be to move code over from the appropriate part of your problem set and into your PA code.

- PSet 2 _11. cap_variants_ helps create all the variants of the strings needed for checking
- PSet 2 _15. sha256_stdin_ helps with the main loop that does SHA on values from input (problems 14 and 16 are also related)
- Pset 2 _9. shacheck_ helps with understanding how to compare SHA values

## Final Testing

To help testing your PA, we are providing you with a file containing 3 million real plaintext passwords famously found a data breach of the [RockYou
social network](https://en.wikipedia.org/wiki/RockYou) in 2009. You can use the password file present in the `ieng6` servers by reading it into `pwcrack` using
the following commandline if you're in Joe's section:

```
$./pwcrack a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd < /home/linux/ieng6/CSE29_FA25_A00/public/pa2/rockyou_clean.txt
```

and the following command if you're in Aaron's section:

```
$./pwcrack a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd < /home/linux/ieng6/CSE29_FA25_B00/public/pa2/rockyou_clean.txt
```

Note: these are real human-generated passwords, so they may contain profane words (and offensive concepts). We are providing a
censored version of the RockYou password list. Our filtering methodology was to remove any passwords that matched a widely-used 2,800 profane
word list. If you read the contents of the password file, note that you are doing so at your own risk, as we can not guarantee that we removed
all offensive passwords from the list.

### Staff Passwords

All staff members have a secret password, and it is your job to guess it! We will give you the hash of the password, and using the rockyou text, try to find each staff members' password.


## Staff Password Hashes

Below are the SHA256 hashes for each staff member's password. Use your `pwcrack` program and the provided password list to try and discover each password.

- Joe: 20f98ae6a6a9a92ec35aac32c886d9740ef79981220fef4c99cf4f40988a4efa
- Aaron: 4a3a6f674cc8b747cb2d88673e9c8793bc1d345482d528f7773fdc79a831c3d4
- Kruti: d495f914f0de80d3d5c6a7fcbb4dee7cfc778ff8344daa7ee8969957f5c84c78
- Reese: 58fc0705c8790a9fa83ecb2ccdca9c6785d5f38f9ddaeea8c73b3b719155eef5
- Rachel: df073edaf05716720adf0db29f5b70bae528aa5c0f1d992c396a1d12e0c21012
- Andrew: 8976bb3b64a2373cb15cf8a666a8985670f837413fb22b1bd54e505f89d0929f
- Alex: 67ed58bc51c3fed497952300a0e194bdb08530b93ccb1b19e505090ea991e923
- Janet: b4c58e57138b87c5a1b25baa39ae95f0690d16a08f8fe37e42b08d504add6d03
- Elena: e1d03258d633ed07a49a3b2feb4d0b739d0d0d2b3d972d16c6b6295bb4aeb5d0
- Anya: 59d927184680758dc8b3ea7e8922d8f185d096ac57afdbab9fcc10048439ec67
- Sam: 71dd256f3ada5ca87a6d038f0b93691e8260d314c5dabc627f9bfbdc7c7d1ff7
- Miles: 3a9c09a64bb5a3e2f7cda61b034bdffb35088a9f771bed332d0ad9990f68100c
- Travis: f4d853a07583874c6c6d28291c7020867d42009b5cde7bad50ec8e1e9a723e93

### Extra Fun!

You might have trouble with a couple of these passwords. For no additional credit, just fun :), you can see if you can guess the passwords based off of the class. Try to use your program to try all cases of letters!

## Design Questions

1. Real password crackers try many more variations than just uppercasing and lowercasing. Do a little research on password cracking and suggest at least 2 other ways to vary a password to crack it. Describe them both, and for each, write a sentence or two about what modifications you would make to your code to implement them.

2. How much working memory is needed to store all of the variables needed to execute the password cracker? Based on your response would you say that a password cracker is more memory-limited or is it more limited by how fast the process can run the code?

## What to Hand In

- Any .c files you wrote (can be one file or many; it's totally reasonable to only have one). We will run `gcc *.c -o pwcrack -lcrypto` to compile your code, so you should make sure it works when we do that.
- A file **DESIGN.md** (with exactly that name) containing the answers to the design questions

You will hand in your code to the `pa2` assignment on Gradescope. An autograder will give you information about if your code compiles and works on some simple examples like the ones from this writeup. Your implementation and design questions will be graded after the deadline with a mix of automatic and manual grading.

## Resources and Policy

Refer to [the policies on assignments](https://ucsd-cse29.github.io/fa25/#assignments-and-academic-integrity) for working with others or appropriate use of tools like ChatGPT or Github Copilot.

You can use any code from class, lab, or discussion in your work.
