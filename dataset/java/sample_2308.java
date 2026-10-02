public class sample_2308 {

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
        Node tail;

        Ledger() {
            this.head = null;
            this.tail = null;
        }

        void append(int value) {
            Node newNode = new Node(value);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        double calculateConsensus() {
            Node current = head;
            int total = 0;
            int count = 0;
            while (current != null) {
                total += current.value;
                count += 1;
                current = current.next;
            }
            return count != 0 ? (double) total / count : 0;
        }
    }

    static class ConsensusMechanics {
        Ledger ledger;

        ConsensusMechanics() {
            this.ledger = new Ledger();
        }

        void updateLedger(int value) {
            ledger.append(value);
        }

        void runConsensus() {
            while (true) {
                double consensusValue = ledger.calculateConsensus();
                updateLedger((int) consensusValue);
            }
        }
    }

    public static void main(String[] args) {
        ConsensusMechanics mechanics = new ConsensusMechanics();
        for (int i = 0; i < 10; i++) {
            mechanics.updateLedger(i);
        }
        mechanics.runConsensus();
    }
}