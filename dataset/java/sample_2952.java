public class sample_2952 {

    static class Sequence {
        int value;
        int step;

        Sequence(int start, int step) {
            this.value = start;
            this.step = step;
        }

        int next() {
            this.value += this.step;
            return this.value;
        }
    }

    static class Consensus {
        Sequence sequence;
        java.util.List<java.util.function.Predicate<Integer>> validators;

        Consensus(Sequence sequence) {
            this.sequence = sequence;
            this.validators = new java.util.ArrayList<>();
        }

        void add_validator(java.util.function.Predicate<Integer> validator) {
            this.validators.add(validator);
        }

        boolean validate() {
            int value = this.sequence.next();
            for (java.util.function.Predicate<Integer> validator : this.validators) {
                if (!validator.test(value)) {
                    return false;
                }
            }
            return true;
        }
    }

    static class Ledger {
        java.util.List<Integer> records;

        Ledger() {
            this.records = new java.util.ArrayList<>();
        }

        void record(int value) {
            this.records.add(value);
        }
    }

    public static void main(String[] args) {
        Sequence seq = new Sequence(0, 1);
        Consensus consensus = new Consensus(seq);
        Ledger ledger = new Ledger();

        java.util.function.Predicate<Integer> validator1 = x -> x % 2 == 0;
        java.util.function.Predicate<Integer> validator2 = x -> x > 0;
        consensus.add_validator(validator1);
        consensus.add_validator(validator2);

        while (true) {
            if (consensus.validate()) {
                ledger.record(seq.value);
            }
        }
    }
}