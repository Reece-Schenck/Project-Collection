//for queue and math
import java.util.*;

public class BinarySearchTree{

  //inserts a new node to the proper position
  public Node insert(Node newNode, int val){
    if(newNode == null){
      return NewNode(val);
    }
        
    if(val < newNode.value){
      newNode.left = insert(newNode.left, val);
    } 
    else if((val > newNode.value)){
      newNode.right = insert(newNode.right, val);
    }
      return newNode;
  }
  
  
  //creates a new node
  public Node NewNode(int num){
    Node newNode = new Node();

    newNode.value = num;
    newNode.left = null;
    newNode.right = null;

    return newNode;
  }


  //traverses through the tree to see if the node exists
  public boolean nodeExists(Node possibleNode, int val){
        
    boolean exists = false;

    if(possibleNode == null){
      return exists;
    }
                
    while(possibleNode != null){
      if(val < possibleNode.value){
        possibleNode = possibleNode.left;
      }
      else if(val > possibleNode.value){
        possibleNode = possibleNode.right;
      }
      else{
        exists = true;
        break;
      }
    }
        
    return exists;
  }


  //traverses down the left side of the tree until it reaches the bottom / min
  public int getMin(Node smallestNode){
    if(smallestNode == null){
      System.out.println("The tree is empty");
      return -1;
    }
        
    while(smallestNode.left != null){
      smallestNode = smallestNode.left;
    }
        
    return smallestNode.value;
  }


  //traverses down the right side of the tree until it reaches the bottom / nmax
  public int getMax(Node biggestNode){
    if(biggestNode == null){
      System.out.println("The tree is empty");
      return -1;
    }
        
    while(biggestNode.right != null){
      biggestNode = biggestNode.right;
      }
        
    return biggestNode.value;
  }

  
  //used to count down the tree until the Nth largest node is found
  static int count = 0;

  public Node NthLargestElement(Node NthNode, int num){

    if(NthNode == null){
      return null;
    }
    
    Node rightNode = NthLargestElement(NthNode.right, num);
    
    if(rightNode != null){
      return rightNode;
    }
    
    count++;
    
    if(count == num){
      return NthNode;
    }
    
    return NthLargestElement(NthNode.left, num);
  }


  //traverses both sides of the tree and takes the height of the biggest one
  //adds one to the total to account for the root
  public int height(Node tree){
    if(tree == null){
      return 0;
    }
    return Math.max(height(tree.left), height(tree.right)) + 1;
  }


  //traverses the tree to find the node that is to be deleted
  //once found a temporary node is made to replace the deleted node
  //this is so that the tree will still remain in order
  public Node deleteNode(Node delNode, int val){
    //if node won't mess up order of the tree, it's deleted immediatly
    if(delNode == null){
      return delNode;
    }
    
    if(val < delNode.value){
      delNode.left = deleteNode(delNode.left, val);
    }else if(val > delNode.value){
      delNode.right = deleteNode(delNode.right, val);
    }else{
      if(delNode.left == null || delNode.right == null){

        Node temp = null;

        if(delNode.left == null){
          temp = delNode.right;
        }else{
          temp = delNode.left;
        }

        return temp;
      }else{
        Node replacementNode = replacement(delNode);
        delNode.value = replacementNode.value;
        
        delNode.right = deleteNode(delNode.right, replacementNode.value);
        return delNode;
      }
    }
    
    return delNode;
  }
  

  //makes sure that moving the replacement node to the deleted nodes spot wont mess up tree order
  public Node replacement(Node repNode){
    if(repNode == null){
      return null;
    }
    
    Node temp = repNode.right;
    
    while(temp.left != null){
      temp = temp.left;
    }
    
    return temp;
  }


  //traverses the tree and orders the elements inorder
  public void inorderSort(Node inNode){
    //immediatly stops in node has no value
    if(inNode == null){
      return;
    }
    
    inorderSort(inNode.left);
    System.out.print(inNode.value + ". ");
    inorderSort(inNode.right);
  }


  //traverses the tree and orders the elements in preorder
  public void preorderSort(Node preNode){
    //immediatly stops in node has no value
    if(preNode == null){
      return;
    }
    
    System.out.print(preNode.value + ". ");
    preorderSort(preNode.left);
    preorderSort(preNode.right);
  }


  //traverses the tree and orders the elements in postorder
  public void postorderSort(Node postNode){
    //immediatly stops in node has no value
    if(postNode == null) {
      return;
    }
    
    postorderSort(postNode.left);
    postorderSort(postNode.right);
    System.out.print(postNode.value+ ". ");
  }


  //searches all the left side of the tree and then the right side to find the node
  //if the node is not found it is not in the tree
  public boolean depthSearch(Node node, int val){

    boolean exists = false;

    if(node == null){
      return exists;
    }

    if(node.value == val){
      exists = true;
    }

    depthSearch(node.left, val);
    depthSearch(node.right, val);

    return exists;
  }

  //searches from the top of the tree to the bottom to find the node
  //if the node is not found it is not in the tree
  public boolean breadthSearch(Node root, int val){
    boolean exists = false;

    Queue<Node> queue = new LinkedList<Node>();
    queue.add(root);
    
    if(root == null){
      return exists;
    }

    if(root.value == val){
      exists = true;
    }

    while(!queue.isEmpty()){
      Node tempNode = queue.poll();

      //add left child to the queue
      if(tempNode.left != null){
        queue.add(tempNode.left);
        if((tempNode.left).value == val){
          exists = true;
          break;
        }
      }
      
      //add right child to the queue
      if (tempNode.right != null){
          queue.add(tempNode.right);
          if((tempNode.right).value == val){
            exists = true;
            break;
          }
      }
    }
    return exists;
  }
}