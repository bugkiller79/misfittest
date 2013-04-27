misfittest
==========



========= PART 3 =======

# 3b
3b find k min numbers of n given numbers. this can be solved by selection algorithm.
first solution:
basically, partition the array into 2 parts (first part elems less than equal to elems of second parts ),
if the # of elems of first part less than K, then go on the small problem (first part)
otherwise print out all elems of first part, then work on the second part with another K = K - # of second parts
the average complexity is O(n)

second solution:
another solution is use a max heap with capacity k.
Iterate all elements of the array. If size of heap less K, just add to the max heap else compare the top elem with the
the current element, if greater then remove that top elem and add the current element. the complexity is O(nlogk)

#3c:
use 2 pointers initially assigned to the head of the given linked list. each step move the first pointer by 1 next, the second pointer by 2 nexts.
if eventually they are of the same pointer --> there is a loop

#3d:
use the algorithm of 3b to find kth smallest elem: k = n/2 . average complexity O(n)

#3e:
the last example of the problem is wrong ( K = 3 should be <= N = 2 ??? )
actually the solution of this problem is combination(
