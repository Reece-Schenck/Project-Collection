### **There was no place to submit the assignment on ILearn at the time of me completing this lab.**

#
I will be giving a breif explanation of what each class does and I will dive into more detail on methods that need more explanation.
#

# For the Node Class:
Each node holds an integer value and 2 other nodes as the left and right children,

# For BinarySearchTree Class:

## Insert:
You put the node of the you are adding onto with the value that you want to add, then that value is compared to the existing node(s) and sorted accordingly.

## NewNode:
It creates a new node with no children and it is assigned the value entered in Insert.

## NodeExists:
It takes on the nodes to be traversed and the value that is being searched for. It is then compared to the values of other nodes moving left or right down the tree until the value is met, otherwise the value is not in the tree.

## GetMin:
This traverses the left side of the tree to the bottom which is then the smallest value.

## GetMax:
This traverses the right side of the tree to the bottom which is then the largest value.

## NthLargestElement:
Here I use a counter outside the method to kepp track of when to stop traversing the right side of the tree in order to acheive the Nth largest value.

## Height:
After importing Math I used it to travers both left and right sides of the tree to find the biggest side before adding 1 to account for the root.

## DeleteNode:
I traverse the tree to find the node to be deleted. I then take that node and store it into a temporary variable. Using that temporary variable I traverse down the rest of the tree to fix the order of the nodes once the new temp node takes the spot of the deleted node.

## Replacement:
This is used in DeleteNode to replace the deleted node by swaping out the deleted nodes value with the one moving to its spot.

## InOrderSort:
This traverses the tree from the left side completly, the to the right side completly, printing the values as it goes in order.

## PreOrderSort:
This sorts the left side of the tree first(starting at the root) printing as it goes before then sorting the right side as it goes meaning that the valuer are not in order, but in pre-order.

## PostOrderSort:
Postorder does the opposite of preorder by sorting from the left side and then right side before ending at the root.

## DepthSearch:
I traversed the left side of the tree and then the right side of the tree, if the value exsisted the the value "true" would be returned, otherwise "false" would be returned.

## BredthSearch:
I started at the top and went down level by level checking both sides while doing so to search for the value. Like with depth search a boolean value was returned according to whether or not the value exsists in the tree.

# For Main Class:
I made an example tree of root nodes and used each method in the BinarySearchTree Class as examples.