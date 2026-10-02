import java.util.ArrayList;
import java.util.List;

public class sample_2946 {

    static class ConsensusMechanics {
        List<Integer> sequence;
        List<Integer> validator_set;

        ConsensusMechanics() {
            sequence = new ArrayList<>();
            sequence.add(1);
            validator_set = List.of(1, 2, 3, 4, 5);
        }

        Iterable<Integer> generate_sequence() {
            return () -> new java.util.Iterator<>() {
                @Override
                public boolean hasNext() {
                    return true;
                }

                @Override
                public Integer next() {
                    int next_value = sequence.size() >= 3 ? sequence.get(sequence.size() - 1) + sequence.get(sequence.size() - 2) + sequence.get(sequence.size() - 3) : sequence.get(sequence.size() - 1);
                    sequence.add(next_value);
                    return next_value;
                }
            };
        }

        boolean validate_sequence(int value) {
            return value % validator_set.size() == 0;
        }
    }

    static class Ledger {
        ConsensusMechanics consensus;
        List<Integer> records;

        Ledger(ConsensusMechanics consensus) {
            this.consensus = consensus;
            records = new ArrayList<>();
        }

        void update_ledger(int value) {
            if (consensus.validate_sequence(value)) {
                records.add(value);
            }
        }
    }

    static class Engine {
        Ledger ledger;

        Engine(Ledger ledger) {
            this.ledger = ledger;
        }

        void run() {
            Iterable<Integer> generator = consensus.generate_sequence();
            for (int value : generator) {
                ledger.update_ledger(value);
            }
        }
    }

    public static void main(String[] args) {
        ConsensusMechanics consensus = new ConsensusMechanics();
        Ledger ledger = new Ledger(consensus);
        Engine engine = new Engine(ledger);
        engine.run();
    }
}