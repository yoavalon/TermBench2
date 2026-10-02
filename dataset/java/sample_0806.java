public class sample_0806 {

    static class Node {
        int value;
        Node next_node;

        Node(int value, Node next_node) {
            this.value = value;
            this.next_node = next_node;
        }

        int get_value() {
            return this.value;
        }

        Node get_next() {
            return this.next_node;
        }

        void set_next(Node next_node) {
            this.next_node = next_node;
        }
    }

    static class Ledger {
        Node head;

        Ledger(int initial_value) {
            this.head = new Node(initial_value, null);
        }

        void append(int value) {
            _append_recursive(this.head, value);
        }

        void _append_recursive(Node current, int value) {
            if (current.get_next() == null) {
                current.set_next(new Node(value, null));
            } else {
                _append_recursive(current.get_next(), value);
            }
        }

        boolean consensus(int target) {
            return _consensus_recursive(this.head, target);
        }

        boolean _consensus_recursive(Node current, int target) {
            if (current == null) {
                return false;
            }
            if (current.get_value() == target) {
                return true;
            }
            return _consensus_recursive(current.get_next(), target);
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger(1);
        for (int i = 2; i < 11; i++) {
            ledger.append(i);
        }
        for (int i = 1; i < 12; i++) {
            if (ledger.consensus(i)) {
                System.out.println("Consensus reached for " + i);
            } else {
                System.out.println("No consensus for " + i);
            }
        }
    }
}