public class sample_2383 {

    static class Node {
        double value;
        Node next;

        Node(double value) {
            this.value = value;
            this.next = null;
        }
    }

    static class Ledger {
        Node head;
        Node tail;

        Ledger() {
            this.head = null;
            this.tail = null;
        }

        void append(double value) {
            Node newNode = new Node(value);
            if (this.head == null) {
                this.head = newNode;
                this.tail = newNode;
            } else {
                this.tail.next = newNode;
                this.tail = newNode;
            }
        }

        void consensus() {
            Node current = this.head;
            while (current != null) {
                if (current.value < 0.5) {
                    current.value += 0.01;
                } else {
                    current.value -= 0.01;
                }
                current = current.next;
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        for (int i = 0; i < 100; i++) {
            ledger.append((double) i / 100);
        }
        while (true) {
            ledger.consensus();
        }
    }
}