# Push_swap

Push Swap is a sorting algorithm project in the 42 Cursus. The goal is to sort a stack of integers using a limited set of instructions.

* 1- create a copy of stack A (in array)
* where the smallest number is on top
* 2- extract the LONGUEST INCREASING SUBSEQ from that copy
* 2- let only the LIS in stack A i.e move all the the other numbers to STACK B
* 3- iterate on stack B and store how much moves are needed for each element
* 4- push the element who needs the least amount of moves
* to its convenable place in STACK A
* 5- once STACK B get empty, move smallest element on top of STACK A
