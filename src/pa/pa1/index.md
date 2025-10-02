# PA1 - UTF-8:

## Due Date: Thursday 10/9 at 11:59pm

## UTF-8

Representing text is straightforward using ASCII: one byte per character fits well within `char[]` and it represents most English text. However, there are many more than 256 characters in the text we use, from non-Latin alphabets (Cyrillic, Arabic, and Chinese character sets, etc.) to emojis and other symbols like €, to accented characters like é and ü.

The [UTF-8 encoding](https://en.wikipedia.org/wiki/UTF-8#Encoding) is the default encoding of text in the majority of software today.
If you've opened a web page, read a text message, or sent an email [in the past 15 years](https://en.wikipedia.org/wiki/UTF-8#/media/File:Unicode_Web_growth.svg) that had any special characters, the text was probably UTF-8 encoded.

Not all software handles UTF-8 correctly! For example, Joe got a marketing email recently with a header “Take your notes further with Connectâ€‹” We're guessing that was supposed to be an ellipsis (…), [UTF-8 encoded as the three bytes 0x11100010 0x10000000 0x10100110](https://www.compart.com/en/unicode/U+2026), and likely the software used to author the email mishandled the encoding and treated it as [three extended ASCII characters](https://en.wikipedia.org/wiki/Extended_ASCII).

This can cause serious problems for real people. For example, people with accented letters in their names can run into issues with sign-in forms (check out Twitter/X account [@yournameisvalid](https://x.com/yournameisvalid?lang=en) for some examples). People with names best written in an alphabet other than Latin can have their names mangled in official documents, and need to have a "Latinized" version of their name for business in the US. Joe had trouble [writing lecture notes](https://x.com/JoePolitz/status/1841175066845069552) because LaTeX does not support UTF-8 by default.

UTF-8 bugs can and do cause security vulnerabities in products we use every day. A simple search for UTF-8 in the CVE database of security vulnerabilities turns up [hundreds of results](https://cve.mitre.org/cgi-bin/cvekey.cgi?keyword=utf-8).

It's useful to get some experience with UTF-8 so you understand how it's supposed to work and can recognize when it doesn't.
To that end, you'll write several functions that work with UTF-8 encoded text, and use them to analyze some example texts.

## Getting Started

You can do your programming however you like; using `vim` on `ieng6` will give you good
practice for labs, exams, and problem sets, but you are not required to use any
particular environment (we'd have no way to check anyway).

To get started, clone the starter code repository in your environment of choice:

```
git clone https://github.com/ucsd-cse29/pa1-utf8
```

## UTF-8 Analyzer

You'll write a program that reads UTF-8 input and prints out some information
about it.

Here's what the output of a sample run of your program should look like:

```
$ ./utf8analyzer
Enter a UTF-8 encoded string: My 🐩’s name is Erdős.
Valid ASCII: false
Uppercased ASCII: MY 🐩’S NAME IS ERDőS.
Length in bytes: 27
Number of code points: 21
Bytes per code point: 1 1 1 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1
Substring of the first 6 code points: My 🐩’s
Code points as decimal numbers: 77 121 32 128041 8217 115 32 110 97 109 101 32 105 115 32 69 114 100 337 115 46
Animal emojis: 🐩
```

You can also test the contents of _files_ by using the `<` operator:

```
$ cat utf8test.txt
My 🐩’s name is Erdős.
$ ./utf8analyzer < utf8test.txt
Enter a UTF-8 encoded string:
Valid ASCII: false
Uppercased ASCII: MY 🐩’S NAME IS ERDőS.
Length in bytes: 27
Number of code points: 21
Bytes per code point: 1 1 1 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1
Substring of the first 6 code points: My 🐩’s
Code points as decimal numbers: 77 121 32 128041 8217 115 32 110 97 109 101 32 105 115 32 69 114 100 337 115 46
Animal emojis: 🐩
```

## Using the Problem Set for your PA

Most of the needed functionality for the PA is in the problem set problems! So
part of your workflow for this PA should be to move code over from the
appropriate part of your problem set and into your PA code.

A good first task is to move over _only_ `is_ascii`, and then write the
corresponding part of `main` needed to read input and print the result for
`is_ascii`, and make sure you can test that. Then move onto `capitalize_ascii`,
and so on.

You can and should save your work by using `git` commits (if you're comfortable
with that), or even just saving copies of your `.c` file when you hit important
milestones. We may ask to see your work from an earlier milestone if you ask us
for help on a function from a later one.

Here we give some hints about how specific problem set problems correspond to
specific lines of output.

- `Valid ASCII:` – **_HW1.15. is_ascii_**
- `Uppercased ASCII:` – **_HW1.13. capitalize_ascii_**

  Here it is important to avoid changing the string that's going to be used for
  the rest of the printing!

- `Length in bytes:` – Are there any built-in `string.h` functions that can help?
- `Number of code points:` – **_HW1.17. Count UTF-8 String Length_**
- `Bytes per code point:` – **_HW1.16. UTF8 Codepoint Size_**

  Here it could be useful to use the function from the problem set inside a loop!

- `Substring of the first 6 code points:` – **_HW1.18. utf8_substring_**
- `Code points as decimal numbers:` – **_HW1.5. Find UTF-8 Codepoint at Index_**

  Another use of a loop with a problem set problem!

- `Animal emojis:` – **_HW1.19. is_animal_emoji_at_**

  Another use of a loop, maybe also combined with some conditionals!

## Testing

We provide 3 basic tests in the `tests` folder - which contain simple tests identifying valid ASCII and converting ASCII lowercase to uppercase characters.

You can see the result for a single test by using:

```
./utf8analyzer < test-file
```

Here are some other ideas for tests you should write. They aren't necessarily comprehensive (you should design your own!) but they should get you started. For each of these kinds of strings, you should check how UTF-8 analyzer handles them:

- Strings with a single UTF-8 character that is 1, 2, 3, 4 bytes
- Strings with two UTF-8 characters in all combinations of 1/2/3/4 bytes. (e.g. `"aa"`, `"aá"`, `"áa"`, `"áá"`, and so on)
- Strings with and without animal emojii, including at the beginning, middle, and end of the string, and at the beginning, middle, and end of the range
- Strings of exactly 5 characters

We recommend _saving your input in files_ and using redirection to test so you don't have to figure out how to type the same UTF8 characters over and over.

## PA Design Questions

You will answer the following questions in your `DESIGN.md` file.

Answer each of these with a few sentences or paragraphs; don't write a whole essay, but use good writing practice to communicate the essence of the idea. A good response doesn't need to be long, but it needs to have attention to detail and be clear. Examples help!

- Another encoding of Unicode is UTF-32, which encodes _all_ Unicode code points in 4 bytes. For things like ASCII, the leading 3 bytes are all 0's. What are some tradeoffs between UTF-32 and UTF-8?

- UTF-8 has a leading `10` on all the bytes past the first for multi-byte code points. This seems wasteful – if the encoding for 3 bytes were instead `1110XXXX XXXXXXXX XXXXXXXX` (where `X` can be any bit), that would fit 20 bits, which is over a million code points worth of space, removing the need for a 4-byte encoding. What are some tradeoffs or reasons the leading `10` might be useful? Can you think of anything that could go wrong with some programs if the encoding didn't include this restriction on multi-byte code points?

## Resources and Policy

Refer to [the policies on assignments](https://ucsd-cse29.github.io/fa25/#assignments-and-academic-integrity) for working with others or appropriate use of tools like ChatGPT or Github Copilot.

You can use any code from class, lab, or discussion in your work.

## What to Hand In

- Any `.c` files you wrote (can be one file or many; it's totally reasonable to only have one). We will run `gcc *.c -o utfanalyzer` to compile your code, so you should make sure it works when we do that.
- A file `DESIGN.md` (with exactly that name) containing the answers to the design questions
- Your tests are in files `tests/*.txt`

Hand in to the `pa1` assignment on Prairie Learn. The submission system will show you the output of compiling and running your program on the test input described above to make sure the baseline format of your submission works. You will not get feedback about your overall grade before the deadline.
