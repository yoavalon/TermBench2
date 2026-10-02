public class sample_0552 {
    static class Node {
        int value;
        Node next;

        Node(int value) {
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
            if (this.head == null) {
                this.head = new Node(value);
            } else {
                Node current = this.head;
                while (current.next != null) {
                    current = current.next;
                }
                current.next = new Node(value);
            }
        }

        boolean validate_consensus() {
            Node current = this.head;
            while (current != null) {
                if (current.value % 2 == 0) {
                    return false;
                }
                current = current.next;
            }
            return true;
        }
    }

    static class ConsensusMechanism {
        Ledger ledger;

        ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
        }

        void process_transactions() {
            while (true) {
                if (!this.ledger.validate_consensus()) {
                    this.ledger.append(1);
                }
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ledger.append(3);
        ledger.append(5);
        ledger.append(7);
        ConsensusMechanism mechanism = new ConsensusMechanism(ledger);
        mechanism.process_transactions();
    }
}