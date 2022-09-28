# Skip-List-implementation
Implementation of skip-list data structure.

## Project description
As you know, if we have a sorted array, we can use binarySearch in it. search with (n Log(O). But in LinkedList, because it is like an array, we cannot access the elements with an index.

We have to search all the elements, that is n(O). SkipList data structure is used for faster searching in linked list.

This data structure consists of multiple layers of two-way link list. The bottom layer is a two-way sorted list link which holds all the elements.
Upper layers are used to improve search speed. In this data building, each nodeIt has 4 pointers down, up, prev, next and a key.

## Details
Suppose we are looking for the number x. The method of searching is that we start from the highest layer and follow the node We find that the value of the next node is greater than x. Then, using the down pointer, come to the lower layer and continue we search and repeat this until we reach the lowest layer.

## Example
For example, we look for the number 96 in the list:

When inserting a key into this data structure, each key from layer i appears with probability p (a random number between zero and one) in layer i+1.

In this way, when inserting a new key, first the place of insertion of that key is found in the ordered list S0 and after insertion in it, it is also inserted in the higher layer with probability p. This continues until the generated random number is less than p.

In this project, consider p as 25.0 and the maximum number of layers as 10.

## More information
For more information, you can refer to the following links:
* https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/skiplists.pdf
* https://www.youtube.com/watch?v=2g9OSRKJuzM
* https://en.wikipedia.org/wiki/Skip_list

## Entry Description
A number of commands are given to your program through input and your program must perform them:
### Insertion
* Insert [number]

Inserts the given number in SkipList
### Delete
* Delete [number]

Removes the given number from SkipList. If the given number does not exist, an error should be printed.
### Search
* Search [number]

If the given number exists in SkipList, it will print true, otherwise it will print false.
### Printing
* Print

It prints all the data in the list in order with a space. If the list is empty, empty should be printed
