public class Main{
    public static void main(String[] args){

        //creates a binary search tree
        BinarySearchTree tree = new BinarySearchTree();

        //Creates the root node
        Node root = null;

        //Adds sorted nodes to the root
        root = tree.insert(root, 9);
        root = tree.insert(root, 2);
        root = tree.insert(root, 8);
        root = tree.insert(root, 11);
        root = tree.insert(root, 5);
        root = tree.insert(root, 6);
        root = tree.insert(root, 3);
        root = tree.insert(root, 14);
        root = tree.insert(root, 15);
        

        //Should be true
        System.out.println(tree.nodeExists(root, 6));


        //should be false
        System.out.println(tree.nodeExists(root, 16));


        //should be 2
        System.out.println(tree.getMin(root));


        //should be 15
        System.out.println(tree.getMax(root));
        

        // should be 11
        Node NthLargest = tree.NthLargestElement(root, 3);

        if(NthLargest != null){
            System.out.println(NthLargest.value);  
        }
        else{
            System.out.println("The value entered returns a null");
        }


        //should be null
        Node NthLargest2 = tree.NthLargestElement(root, 15);

        if(NthLargest2 != null){
            System.out.println(NthLargest2.value);  
        }
        else{
            System.out.println("The value entered returns a null");
        }


        //should be 5
        System.out.println(tree.height(root));


        //should delete the node with value 14
        tree.deleteNode(root, 14);

        //the node with the value 14 should no longer exist(should be false)
        System.out.println(tree.nodeExists(root, 14));


        //prints list of nodes inorder
        tree.inorderSort(root);
        System.out.println("");

        //print list of nodes in preorder
        tree.preorderSort(root);
        System.out.println("");

        //prints list of nodes in post order
        tree.postorderSort(root);
        System.out.println("");

        
        //should return false
        System.out.println(tree.depthSearch(root, 20));

        //should return true
        System.out.println(tree.breadthSearch(root, 3));
    }
}