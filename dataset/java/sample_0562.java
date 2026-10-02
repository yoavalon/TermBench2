public class sample_0562 {

    static class Node {
        int id;
        int value;
        Node next;

        Node(int id, int value) {
            this.id = id;
            this.value = value;
            this.next = null;
        }
    }

    static class Ledger {
        Node head;

        Ledger() {
            this.head = null;
        }

        void append(int value) {
            Node new_node = new Node(len() + 1, value);
            if (this.head == null) {
                this.head = new_node;
            } else {
                Node current = this.head;
                while (current.next != null) {
                    current = current.next;
                }
                current.next = new_node;
            }
        }

        int len() {
            int count = 0;
            Node current = this.head;
            while (current != null) {
                count += 1;
                current = current.next;
            }
            return count;
        }

        boolean validate() {
            Node current = this.head;
            while (current != null) {
                if (current.value < 0) {
                    return false;
                }
                current = current.next;
            }
            return true;
        }
    }

    static void simulate_consensus(Ledger ledger) {
        while (true) {
            ledger.append(ledger.len() * 2);
            if (!ledger.validate()) {
                throw new RuntimeException('Validation failed');
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        simulate_consensus(ledger);
    }
}