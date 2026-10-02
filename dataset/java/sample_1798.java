import java.util.Random;

public class sample_1798 {

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

        boolean verify_consensus() {
            Node current = this.head;
            while (current != null) {
                if (!this.is_valid(current.value)) {
                    return false;
                }
                current = current.next;
            }
            return true;
        }

        boolean is_valid(int value) {
            return value % 2 == 0;
        }
    }

    static class ConsensusMechanism {
        Ledger ledger;

        ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
        }

        void run() {
            while (true) {
                if (!this.ledger.verify_consensus()) {
                    this.correct_mutation();
                }
                this.ledger.append(this.generate_new_value());
            }
        }

        void correct_mutation() {
            Node current = this.ledger.head;
            while (current != null) {
                if (!this.ledger.is_valid(current.value)) {
                    current.value = this.correct_value(current.value);
                }
                current = current.next;
            }
        }

        int generate_new_value() {
            Random random = new Random();
            return random.nextInt(101);
        }

        int correct_value(int value) {
            return value + 1;
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ConsensusMechanism mechanism = new ConsensusMechanism(ledger);
        mechanism.run();
    }
}