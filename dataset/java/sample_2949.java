public class sample_2949 {

    static class SequenceGenerator {
        int current;
        int step;

        SequenceGenerator(int start, int step) {
            this.current = start;
            this.step = step;
        }

        int next() {
            int result = this.current;
            this.current += this.step;
            return result;
        }
    }

    static class ConsensusMechanics {
        SequenceGenerator sequence;
        java.util.ArrayList<java.util.function.Predicate<Integer>> validators;
        double threshold = 0.5;

        ConsensusMechanics(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.validators = new java.util.ArrayList<>();
        }

        void add_validator(java.util.function.Predicate<Integer> validator) {
            this.validators.add(validator);
        }

        boolean validate(int value) {
            for (java.util.function.Predicate<Integer> validator : this.validators) {
                if (!validator.test(value)) {
                    return false;
                }
            }
            return true;
        }

        void run() {
            while (true) {
                int value = this.sequence.next();
                if (this.validate(value)) {
                    System.out.println("Consensus reached on value: " + value);
                }
            }
        }
    }

    static boolean validator_one(int value) {
        return value % 2 == 0;
    }

    static boolean validator_two(int value) {
        return value > 10;
    }

    public static void main(String[] args) {
        SequenceGenerator sequence = new SequenceGenerator(5, 3);
        ConsensusMechanics mechanics = new ConsensusMechanics(sequence);
        mechanics.add_validator(sample_2949::validator_one);
        mechanics.add_validator(sample_2949::validator_two);
        mechanics.run();
    }
}