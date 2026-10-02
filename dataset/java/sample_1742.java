import java.util.Random;

class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    LinkedList() {
        this.head = null;
    }

    void append(int value) {
        Node newNode = new Node(value);
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        Node last = this.head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = newNode;
    }

    void display() {
        Node current = this.head;
        while (current != null) {
            System.out.print(current.value + " -> ");
            current = current.next;
        }
        System.out.println("None");
    }
}

class sample_1742 {
    static Random random = new Random();

    static void mutateList(LinkedList linkedList) {
        Node current = linkedList.head;
        while (current != null) {
            if (random.nextBoolean()) {
                current.value += 1;
            }
            current = current.next;
        }
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        for (int i = 0; i < 10; i++) {
            ll.append(i);
        }
        ll.display();
        while (true) {
            mutateList(ll);
            ll.display();
        }
    }
}