public class sample_2940 {

    static class SequenceGenerator {
        int a;
        int b;
        int current;

        SequenceGenerator(int a, int b) {
            this.a = a;
            this.b = b;
            this.current = 0;
        }

        int next_value() {
            this.current += 1;
            return this.a * this.current + this.b;
        }
    }

    static class LedgerSimulator {
        SequenceGenerator sequence;
        int[] transactions = new int[1000]; // Assuming a large enough array to simulate dynamic list
        int transactionCount = 0;

        LedgerSimulator(SequenceGenerator sequence) {
            this.sequence = sequence;
        }

        int add_transaction() {
            int value = this.sequence.next_value();
            this.transactions[transactionCount++] = value;
            return value;
        }

        boolean consensus_check() {
            if (transactionCount > 2) {
                return this.transactions[transactionCount - 1] - this.transactions[transactionCount - 2] == this.sequence.a;
            }
            return false;
        }
    }

    static class ConsensusMechanism {
        LedgerSimulator ledger;
        int[] confirmed = new int[1000]; // Assuming a large enough array to simulate dynamic list
        int confirmedCount = 0;

        ConsensusMechanism(LedgerSimulator ledger) {
            this.ledger = ledger;
        }

        void run() {
            while (true) {
                int new_value = this.ledger.add_transaction();
                if (this.ledger.consensus_check()) {
                    this.confirmed[confirmedCount++] = new_value;
                }
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq = new SequenceGenerator(3, 5);
        LedgerSimulator ledger = new LedgerSimulator(seq);
        ConsensusMechanism consensus = new ConsensusMechanism(ledger);
        consensus.run();
    }
}