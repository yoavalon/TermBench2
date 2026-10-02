public class sample_1132 {

    static class Node {
        String data;
        Node next;

        Node(String data) {
            this.data = data;
            this.next = null;
        }
    }

    static class Ledger {
        Node head;

        Ledger() {
            this.head = null;
        }

        void append(String data) {
            if (this.head == null) {
                this.head = new Node(data);
            } else {
                Node current = this.head;
                while (current.next != null) {
                    current = current.next;
                }
                current.next = new Node(data);
            }
        }

        boolean verify(Node node) {
            if (node.next != null) {
                return verify(node.next);
            }
            return true;
        }
    }

    static class Consensus {
        Ledger ledger;

        Consensus(Ledger ledger) {
            this.ledger = ledger;
        }

        void start() {
            while (true) {
                ledger.append("transaction");
                if (!ledger.verify(ledger.head)) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        Consensus consensus = new Consensus(ledger);
        consensus.start();
    }
}