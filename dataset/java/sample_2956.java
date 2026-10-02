public class sample_2956 {
    static class SequenceGenerator {
        int a;
        int b;

        SequenceGenerator(int a, int b) {
            this.a = a;
            this.b = b;
        }

        int generate_next(int current) {
            return current * a + b;
        }
    }

    static class ConsensusMechanism {
        SequenceGenerator sequence;
        int current_value;

        ConsensusMechanism(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.current_value = 0;
        }

        void update_value() {
            this.current_value = sequence.generate_next(this.current_value);
        }

        boolean validate_consensus(int target) {
            return this.current_value == target;
        }
    }

    static class DecentralizedLedger {
        ConsensusMechanism consensus_mechanism;
        int target_value;

        DecentralizedLedger(ConsensusMechanism consensus_mechanism) {
            this.consensus_mechanism = consensus_mechanism;
            this.target_value = 1000;
        }

        void run() {
            while (true) {
                this.consensus_mechanism.update_value();
                if (this.consensus_mechanism.validate_consensus(this.target_value)) {
                    System.out.println('Consensus reached');
                } else {
                    System.out.println('Updating value...');
                }
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq_gen = new SequenceGenerator(2, 1);
        ConsensusMechanism consensus_mech = new ConsensusMechanism(seq_gen);
        DecentralizedLedger ledger = new DecentralizedLedger(consensus_mech);
        ledger.run();
    }
}