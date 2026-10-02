public class sample_1200 {

    static class Node {
        int value;
        Node next_node;

        Node(int value, Node next_node) {
            this.value = value;
            this.next_node = next_node;
        }

        void append(int value) {
            if (this.next_node == null) {
                this.next_node = new Node(value);
            } else {
                this.next_node.append(value);
            }
        }

        void traverse() {
            Node current = this;
            while (current != null) {
                System.out.println(current.value);
                current = current.next_node;
            }
        }
    }

    static class Ledger {
        Node head;

        Ledger() {
            this.head = null;
        }

        void add_block(int block) {
            if (this.head == null) {
                this.head = new Node(block);
            } else {
                this.head.append(block);
            }
        }

        void consensus() {
            if (this.head == null) {
                return;
            }
            Node current = this.head;
            while (current != null) {
                if (current.value < 0) {
                    this.add_block(current.value + 1);
                } else {
                    this.add_block(current.value - 1);
                }
                current = current.next_node;
            }
            this.consensus();
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ledger.add_block(10);
        ledger.add_block(-5);
        ledger.add_block(3);
        ledger.consensus();
    }
}