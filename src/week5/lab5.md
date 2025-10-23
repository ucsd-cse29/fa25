# Lab 4 Reference Document


Part 1: `.vimrc` addendum and ssh `config`
--------------------------------

In the file `~/.vimrc` on ieng6, add:

```
set cindent
```

On Your computer (not ieng6) create the file `~/.ssh/config`:

```
Host <shortcut> <possibly more shortcuts>
    HostName <the host name of the ssh server>
    User <your username on the ssh server>

```

Part 2: GDB Debugging
--------------------------------

(clone the github classroom repo from here: <>)

Debug the buggy `index_of` file.  


Part 3: Extra Options
---------------------

Expand your program to handle extra flags: 

`./mysearch -n PATTERN` : print line numbers before each line

`./mysearch -v PATTERN` : print only lines that don't contain PATTERN

`./mysearch -c PATTERN` : don't print pattern matches, just print out the count of matching lines at the end

Each person in your group should implement a different one of these; you'll need all three to do the whiteboard activity.

You can use the `strcmp()` function to check whether two strings are equal.

Work Check-off
--------------

~~Make sure your program supports at least one of `-n`, `-v`, or `-c`, and commit/push your code.~~  
Make sure you have committed and pushed the code you were working on for your `-n`, `-v`, or `-c` file from the lab activity.

If done early, implement some of the following (in no particular order)
------------------------------------------------------------------------------

-   Make your program handle all 3 of `-n`, `-v`, and `-c`.

-   Add the option `-i`, for case-insensitive search (i.e. `search -i pattern` should match lines containing "Pattern" or "PATTERN")

-   Use [ANSI Escape Codes](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797) to make your program bold or highlight the matches in every matching line, either always or with a `--color` option. (more info on [Wikipedia](https://en.wikipedia.org/wiki/ANSI_escape_code))

-   Add the option `-A` to print extra context after a match, so e.g. `search -A 2 pattern` would print an extra 2 lines after every match.

-   Add the option `-B` to print extra context before a match (`search -B 2 pattern` would print an extra 2 lines before every match.) (Note: to be able to do this in C with the tools we've seen so far, you might need to set an upper limit on how many lines back your program will be able to support)

-   Make your program handle options more flexibly, e.g. it could:

    -   be able to handle multiple options simultaneously 

    -   accept arguments in any order

    -   exit with a help message for unrecognized options (e.g. -f, -o) instead of treating them as search patterns. (Or if you pass it the -h or --help options) 

    -   if it sees the option "--",  treat all following arguments as search patterns, even if they start with a "-". (This is how actual command line programs allow you to search for the string "-n" instead of specifying the "-n" option.)

    -   allow long versions of options, e.g. `--invert-match`, `--line-number`, `--count`, etc
    

