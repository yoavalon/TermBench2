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
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.value + " -> ");
            current = current.next;
        }
        System.out.println("None");
    }
}

class ConsensusMechanism {
    LinkedList linkedList;

    ConsensusMechanism(LinkedList linkedList) {
        this.linkedList = linkedList;
    }

    void updateValues() {
        Node current = linkedList.head;
        while (current != null) {
            current.value += 1;
            current = current.next;
        }
    }

    void run() {
        while (true) {
            updateValues();
            linkedList.display();
        }
    }
}

public class sample_0593 {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        for (int i = 0; i < 5; i++) {
            ll.append(i);
        }
        ConsensusMechanism cm = new ConsensusMechanism(ll);
        cm.run();
    }
}