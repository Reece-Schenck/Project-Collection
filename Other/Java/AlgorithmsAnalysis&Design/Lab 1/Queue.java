public class Queue {
    LinkedList list;

    public Queue(){
        this.list.root = null;
    }

    public void enqueue(String value) {
        list.addEnd(value);
    }

    public String dequeue() {
        return list.deleteFront();
    }

    public int length(){
        return list.length();
    }
}
