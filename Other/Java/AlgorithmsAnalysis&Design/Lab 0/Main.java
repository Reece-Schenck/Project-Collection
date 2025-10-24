public class Main {
    public static void main(String[] args) {
        //creates the linked listItems
        //node4 does not link to another listItem
        listItem node4 = new listItem(1, null);
        listItem node3 = new listItem(2, node4);
        listItem node2 = new listItem(3, node3);
        listItem node1 = new listItem(4, node2);

        //gets values of nodes and prints it
        System.out.println(node1.getValue());
        System.out.println(node2.getValue());
        System.out.println(node3.getValue());
        System.out.println(node4.getValue());
    }
}   