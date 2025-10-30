# Lab 6 Reference Document


Part 1: Valgrind
--------------------------------


(clone the github classroom repo from here: <>)


Notice how the heap summary gives you information on where each memory error occurs. Inspect the source code to see how each type is caused.

- Definitely lost: Besides myself, memory leaks are also considered "definitely lost" when the pointer to the memory becomes inaccessible. This can happen when the pointer is deleted when a function ends and its stack frame is deleted, or when the pointer is set to another value.
- Indirectly lost: Blocks of memory are considered "indirectly lost" when there exists a pointer in another leaked memory to the block. In this case, the memory pointed to by `pp` (i.e. `*pp`) is definitely lost, and the memory pointed to by `*pp` (i.e. `**pp`) is indirectly lost.
- Possibly lost: "Possibly lost" memory leaks occur when we have a pointer to some part of the leaked memory, but not to the base of the memory block, likely because the pointer was modified. In this case, we allocate an array of integers, then move the pointer to point to the middle of the array.
- Still reachable: Memory leaks are "still reachable" when the pointer is not lost when program exits, but the memory is still unfreed. This can occur when a global variable contains a pointer to leaked memory.
- Suppressed: Users can specify the flag `--suppressions=<filename>` to Valgrind to intentionally ignore leaks that are known to be harmless or unavoidable. If you want to learn how to use this flag, you can check out this [StackOverflow post](https://stackoverflow.com/questions/13692890/suppress-potential-memory-leak-in-valgrind), although in our (at least one tutor and at least one TA) experience this flag is seldom used, if at all.


Part 2: Header Guards
--------------------------------





Part 3: Makefiles
---------------------

Work Check-off
--------------

To Be Determined
