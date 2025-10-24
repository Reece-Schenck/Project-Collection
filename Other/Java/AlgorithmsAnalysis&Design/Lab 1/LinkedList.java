public class LinkedList {
    //singly linked list
    Node root;
    //Node tail;

    public LinkedList(){
        this.root = null;
    }

    //traverses list and adds at the end
    //Took this code from a previous project in SD1 and slightly modified it
    public void addEnd(String item) {
        if (this.root == null) {
            this.root = new Node(item);
            System.out.println("The item " + item + " has been added successfully.");
        } else {
            Node tempNode = this.root;
            while (tempNode.nextNode != null) {
                tempNode = tempNode.nextNode;
            }
            tempNode.nextNode = new Node(item);
            System.out.println("The item " + item + " has been added successfully.");
        }
    }

    //Replaces root
    //Used code from previous add and heavily changed it
    public void addFront(String item) {
        if (this.root == null) {
            this.root = new Node(item);
            System.out.println("The item " + item + " has been added successfully.");
        } else {
            Node tempNode = this.root;
            this.root = new Node(item);
            while (tempNode.nextNode != null) {
                tempNode = tempNode.nextNode;
            }
            tempNode.nextNode = null;
            System.out.println("The item " + item + " has been added successfully.");
        }
    }

    //Used previous project's delete method as a base and heavily modified for both deleteEnd and deleteFront
    public String deleteEnd() {
        if (this.root == null) {
            return("The root hasn't been set yet.");
        } else {
            Node tempNode = this.root;
            while (tempNode.nextNode != null) {
                tempNode = tempNode.nextNode;
            }
            String deleted = tempNode.item;
            System.out.println("The item " + deleted + " has been deleted");
            tempNode = null;
            return deleted;
        }
    }

    public String deleteFront() {
        if (this.root == null) {
            return("The root hasn't been set yet.");
        } else {
            String deleted = this.root.item;
            Node tempNode = this.root;
            this.root = tempNode.nextNode;
            while (tempNode.nextNode != null) {
                tempNode = tempNode.nextNode;
            }
            System.out.println("The item " + deleted + " has been deleted");
            return deleted;
        }
    }

    //I took this code from a project I did in SD1
    public int length() {
        int length = 0;
        if (this.root != null) {
            Node tempNode = this.root;
            length++;
            while (tempNode.nextNode != null) {
                tempNode = tempNode.nextNode;
                length++;
            }
        }
        return length;
    }

    public void print(){
        if (this.root == null) {
            System.out.println("There is nothing in the linked list.");
        } else {
            System.out.println("");
            Node tempNode = this.root;
            System.out.print(tempNode);
            while (tempNode.nextNode != null) {
                tempNode = tempNode.nextNode;
                System.out.print(tempNode);
            }
        }
    }
}