public class sample_2681 {

    static class SequenceGenerator {
        int start;
        int stop;

        SequenceGenerator(int start, int stop) {
            this.start = start;
            this.stop = stop;
        }

        int[] generate_sequence() {
            int[] sequence = new int[stop - start + 1];
            int current = start;
            int index = 0;
            while (current <= stop) {
                sequence[index] = current;
                current += 1;
                index += 1;
            }
            return sequence;
        }
    }

    static class SemanticValidator {
        int[] sequence;

        SemanticValidator(int[] sequence) {
            this.sequence = sequence;
        }

        boolean validate() {
            boolean valid = true;
            for (int i = 0; i < sequence.length - 1; i++) {
                if (sequence[i] + 1 != sequence[i + 1]) {
                    valid = false;
                    break;
                }
            }
            return valid;
        }
    }

    static class ResultFormatter {
        int[] sequence;
        boolean is_valid;

        ResultFormatter(int[] sequence, boolean is_valid) {
            this.sequence = sequence;
            this.is_valid = is_valid;
        }

        String format() {
            String status = is_valid ? "valid" : "invalid";
            StringBuilder sb = new StringBuilder("Sequence: ");
            for (int num : sequence) {
                sb.append(num).append(" ");
            }
            sb.append("- Status: ").append(status);
            return sb.toString();
        }
    }

    public static void main(String[] args) {
        int start = 1;
        int stop = 10;
        SequenceGenerator generator = new SequenceGenerator(start, stop);
        int[] sequence = generator.generate_sequence();
        SemanticValidator validator = new SemanticValidator(sequence);
        boolean is_valid = validator.validate();
        ResultFormatter formatter = new ResultFormatter(sequence, is_valid);
        System.out.println(formatter.format());
    }
}