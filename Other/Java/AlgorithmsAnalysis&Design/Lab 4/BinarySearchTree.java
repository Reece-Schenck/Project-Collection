//Taken from previous SD1 project and heavily edited
import java.util.*;

public class BinarySearchTree{
    //String path = "";

    //public BinarySearchTree(){
        //this.path = path;
    //}
    int comparisonTotal = 0;
    double totalTime = 0;
    long startTime;
    long endTime;
    long elapsedTime;

    //inserts a new node to the proper position
    public Node insert(Node newNode, String val){
        if(newNode == null){
            //path = "";
            return NewNode(val);
        }
       
        //if(val < newNode.value)
        if(val.compareToIgnoreCase(newNode.value) < 0){
            newNode.path = newNode.path + "L ";
            newNode.left = insert(newNode.left, val);
        }
        //else if(val > newNode.value) 
        else if(val.compareToIgnoreCase(newNode.value) > 0){
            newNode.path = newNode.path + "R ";
            newNode.right = insert(newNode.right, val);
        }
        //System.out.println(path);
        return newNode;
    }
  
    //creates a new node
    public Node NewNode(String value){
        Node newNode = new Node();

        newNode.value = value;
        newNode.left = null;
        newNode.right = null;

        newNode.path = "";

        return newNode;
    }

    public String getPath(Node newNode){
        return newNode.path;
    }

    public void clearPath(Node newNode){
        newNode.path = "";
    }


    //traverses the tree and prints the elements inorder
    //elements are seperated by a '.'
    public void inorderSort(Node inNode){
        //immediatly stops in node has no value
        if(inNode == null){
            return;
        }
    
        inorderSort(inNode.left);
        System.out.print(inNode.value + ". ");
        inorderSort(inNode.right);
    }

    //add times + comparison
    public void search(Node node, String target){
        node.path = "";
        int comparisons = 0;
        startTime = System.nanoTime();
        while(target.compareToIgnoreCase(node.value) != 0){
            if(target.compareToIgnoreCase(node.value) < 0){
                node.path = node.path + "L ";
                node = node.left;
            }else{
                node.path = node.path + "R ";
                node = node.right;
            }
            comparisons++;
        }
        endTime = System.nanoTime();
        elapsedTime = endTime - startTime;
        totalTime = totalTime + elapsedTime;

        System.out.println("Path of " + target + ":");
        System.out.println(node.path);

        System.out.println("Number of comparisons: ");
        System.out.println(comparisons);
        comparisonTotal = comparisonTotal + comparisons;

        System.out.println("Time in nanoseconds: ");
        System.out.println(elapsedTime);
    }

    public void averageComp(int length){
        double averageComp = comparisonTotal / length;
        System.out.println("Average Comparisons: ");
        System.out.format("%.2f%n", averageComp);

    }

    public void averageTime(int length){
        double averageTime = totalTime / length;
        System.out.println("Average time in nanoseconds:");
        System.out.format("%.2f%n", averageTime);
    }
}