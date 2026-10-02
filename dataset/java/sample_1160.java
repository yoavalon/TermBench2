class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    LinkedList() {
        this.head = null;
    }

    void append(int data) {
        Node new_node = new Node(data);
        if (this.head == null) {
            this.head = new_node;
            return;
        }
        Node last = this.head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = new_node;
    }

    void remove(int key) {
        Node temp = this.head;
        if (temp != null) {
            if (temp.data == key) {
                this.head = temp.next;
                temp = null;
                return;
            }
        }
        while (temp != null) {
            if (temp.data == key) {
                break;
            }
            Node prev = temp;
            temp = temp.next;
        }
        if (temp == null) {
            return;
        }
        prev.next = temp.next;
        temp = null;
    }
}

class sample_1160 {
    static void recursive_consensus(Node node, int value) {
        if (node == null) {
            return;
        }
        if (node.data == value) {
            node.data = value;
        }
        recursive_consensus(node.next, value);
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        for (int i = 0; i < 100; i++) {
            ll.append(i);
        }
        recursive_consensus(ll.head, 50);
        main();
    }
}