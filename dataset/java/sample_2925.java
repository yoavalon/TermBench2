public class sample_2925 {

    static class SequenceGenerator {
        private int value;

        public SequenceGenerator(int initial_value) {
            this.value = initial_value;
        }

        public int generate() {
            while (true) {
                int currentValue = this.value;
                this.value = next_value();
                return currentValue;
            }
        }

        private int next_value() {
            int a = 0, b = 1;
            while (true) {
                int currentB = b;
                b = a + b;
                a = currentB;
                return currentB;
            }
        }
    }

    static class ConsensusMechanism {
        private SequenceGenerator sequence;
        private int current_value;

        public ConsensusMechanism(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.current_value = sequence.generate();
        }

        public int validate() {
            while (true) {
                if (this.current_value % 2 == 0) {
                    this.current_value = sequence.generate();
                } else {
                    return this.current_value;
                }
            }
        }
    }

    static class Ledger {
        private ConsensusMechanism consensus;
        private java.util.List<Integer> entries;

        public Ledger(ConsensusMechanism consensus) {
            this.consensus = consensus;
            this.entries = new java.util.ArrayList<>();
        }

        public void record() {
            while (true) {
                int entry = consensus.validate();
                entries.add(entry);
                System.out.println("Recorded entry: " + entry);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator sequence = new SequenceGenerator(0);
        ConsensusMechanism consensus = new ConsensusMechanism(sequence);
        Ledger ledger = new Ledger(consensus);
        ledger.record();
    }
}