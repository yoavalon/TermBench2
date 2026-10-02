import java.util.Random;

class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    Node head;

    Ledger() {
        this.head = null;
    }

    void append(int value) {
        if (head == null) {
            head = new Node(value);
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new Node(value);
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
        if (count > 0) {
            return (double) total / count;
        }
        return 0;
    }
}

class ConsensusMechanism {
    Ledger ledger;

    ConsensusMechanism(Ledger ledger) {
        this.ledger = ledger;
    }

    void updateLedger(double newValue) {
        ledger.append((int) newValue);
    }

    void checkConsensus() {
        Random random = new Random();
        while (true) {
            double consensusValue = ledger.calculateConsensus();
            if (consensusValue > 0.5) {
                System.out.println('Consensus reached: ' + consensusValue);
            } else {
                System.out.println('Updating ledger with new value...');
                updateLedger(random.nextDouble());
            }
        }
    }
}

public class sample_2335 {
    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ConsensusMechanism mechanism = new ConsensusMechanism(ledger);
        mechanism.checkConsensus();
    }
}