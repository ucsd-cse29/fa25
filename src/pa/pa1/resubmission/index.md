# PA1 Resubmission: Due Date 10/23 at 11:59pm

## If you want to resubmit PA1, please read this section carefully. You need to pass all the tests in the original PA1, while also implementing an extra function described below.

### `void next_utf8_char(char str[], int32_t cpi, char result[])`

Takes a UTF-8 encoded string and a codepoint index. Calculates the codepoint at that index. Then, calculates the code point with value one higher (so e.g. for ”é“ U+00E9 that would be “ê” (U+00EA), and for “🐩” (U+1F429) that would be “🐪” (U+1F42A)). Saves the encoding of that code point in the `result` array starting at index `0`.

#### Example Usage:

``` c
char str[] = "Joséph";
char result[100];
int32_t idx = 3;
next_utf8_char(str, idx, result);
printf("Next Character of Codepoint at Index 3: %s\n",result);
// 'é' is the 4th codepoint represented by the bytes 0xC3 0xA9
// 'ê' in UTF-8 hex bytes is represented as 0xC3 0xAA

=== Output ===
Next Character of Codepoint at Index 3: ê
```

Now, Your final output on running the `utfanalyzer` code that will be graded should contain this extra line:

```
Next Character of Codepoint at Index 3: FILL
```

**Note:** If the number of codepoints in the input string _is less than 4_, this added line would only have the prompt _without any character_ as follows:

```
Next Character of Codepoint at Index 3: 
```

The complete program output for example, should look like:

```
$ ./utf8analyzer
Enter a UTF-8 encoded string: My 🐩’s name is Erdős.
Valid ASCII: false
Uppercased ASCII: "MY 🐩’S NAME IS ERDőS."
Length in bytes: 27
Number of code points: 21
Bytes per code point: 1 1 1 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1
Substring of the first 6 code points: "My 🐩’s"
Code points as decimal numbers: 77 121 32 128041 8217 115 32 110 97 109 101 32 105 115 32 69 114 100 337 115 46
Animal emojis: 🐩
Next Character of Codepoint at Index 3: 🐪
```

(All our tests will check for this newly added line, in addition to lines from the original PA)

### You will also need to answer the following updated DESIGN question in your resubmission

Consider the 3-byte sequence `11100000 10000000 10100001`. Answer the following questions:

- What code point does it encode in UTF-8, and what character is that?
- What are the three other ways to encode that character?
- Give an example of a character that has exactly three encodings (but not four, like the one in the previous example does)
- What are some problems with having these multiple encodings, especially for ASCII characters? A web search for “overlong UTF-8 encoding” may be useful here.
