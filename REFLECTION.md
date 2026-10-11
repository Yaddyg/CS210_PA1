# #1) Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

Concat only needs to merge two lists of the same representation because ArrayList and LinkedList store their elements differently. ArrayList stores pointers in an array, so concat transfers each pointer into a new slot, 
while LinkedList connects the nodes of each list. It would be possible to support merging different list representations, but it would require additional conversion and logic. In our implementation, dynamic_cast prevents incompatible lists
from merging by printing an error and returning without changing either list.

# #2) Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.
The three pointers in my implementation are the previous, current, and next pointer. Previous points to the node we want to point to in backwards order.
Current is the node were reversing to, and next saves the next node before we flip the link. All three are important to our process. 
Losing previous will make us lost since we wont know whats the next node in reverse we want. Losing current means we do not know our node, and losing next means losing our connection to the remaining nodes in the list.

# #3) addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?
Both addAnywhere() and deleteAnywhere() use bounds checks to prevent invalid positions. 
For addAnywhere(), the valid range is 0 through size_,. 
For deleteAnywhere(), the valid range is 0 through size_ - 1, since we can only delete existing elements. 
If a position is outside these ranges, the implementation prints "Position invalid" and returns without changing the list.

# #4) In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?
We traverse the list because our LinkedList does not use a tail pointer. If it did use a tail pointer concat would perform better since no loop would be needed. 
You would have to update the tail once again after the concat is succesful so that tail now points to the end of the concated list. 
addFront and deleteFront are seperate from this because a tail pointer does not affect them, they only work with the head. 

# #5) Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.
in addAnywhere, we shift all elements to the right by one. Once we shift them, we can add the new element at the positon we want and increase the size_ by one. 
If we shift in the wrong direction we would overwrite the entire array and its existing elements, losing data we need and just messing up the array. 

# #6) Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.
In main, the line to reverse is this,   table1->reverse();. Without this call, the cards would just continue in the same order. In a visible uno game, the reverse card would be useless 
if the reverse call was missing. It would have 0 effect on the game. 