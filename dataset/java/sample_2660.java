public class sample_2660 {

    static class SequenceGenerator {
        int length;
        int[] sequence;

        SequenceGenerator(int length) {
            this.length = length;
            this.sequence = new int[length];
        }

        int[] generate_sequence() {
            for (int i = 0; i < this.length; i++) {
                this.sequence[i] = this.calculate_value(i);
            }
            return this.sequence;
        }

        int calculate_value(int index) {
            if (index % 2 == 0) {
                return index * index;
            } else {
                return (int) Math.pow(2, index);
            }
        }
    }

    static class ConsensusMechanic {
        int[] sequence;
        int[] consolidated;

        ConsensusMechanic(int[] sequence) {
            this.sequence = sequence;
            this.consolidated = new int[sequence.length];
        }

        int[] apply_consensus() {
            for (int value : this.sequence) {
                this.consolidated[this.sequence.length - 1] = this.validate_value(value);
            }
            return this.consolidated;
        }

        int validate_value(int value) {
            if (value > 10) {
                return value - 5;
            } else {
                return value * 2;
            }
        }
    }

    public static void main(String[] args) {
        int length = 20;
        SequenceGenerator generator = new SequenceGenerator(length);
        int[] sequence = generator.generate_sequence();
        ConsensusMechanic mechanic = new ConsensusMechanic(sequence);
        int[] result = mechanic.apply_consensus();
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}