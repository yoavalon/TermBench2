public class sample_2636 {

    static class SequenceGenerator {
        int a;
        int b;

        SequenceGenerator(int a, int b) {
            this.a = a;
            this.b = b;
        }

        int[] generate(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    result[i] = this.a;
                } else {
                    result[i] = this.b;
                }
            }
            return result;
        }
    }

    static class ConsensusMechanism {
        int[] sequence;

        ConsensusMechanism(int[] sequence) {
            this.sequence = sequence;
        }

        boolean verify() {
            int count_a = 0;
            for (int x : this.sequence) {
                if (x == this.sequence[0]) {
                    count_a++;
                }
            }
            int count_b = this.sequence.length - count_a;
            return count_a == count_b;
        }
    }

    static class Executor {
        SequenceGenerator generator;
        ConsensusMechanism verifier;

        Executor(SequenceGenerator generator, ConsensusMechanism verifier) {
            this.generator = generator;
            this.verifier = verifier;
        }

        Object[] run() {
            int[] sequence = this.generator.generate(10);
            boolean is_valid = this.verifier.verify();
            return new Object[]{sequence, is_valid};
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq_gen = new SequenceGenerator(1, 0);
        ConsensusMechanism consensus = new ConsensusMechanism(new int[0]);
        Executor executor = new Executor(seq_gen, consensus);
        Object[] result = executor.run();
        int[] sequence = (int[]) result[0];
        boolean validity = (boolean) result[1];
        System.out.print("Sequence: ");
        for (int num : sequence) {
            System.out.print(num + " ");
        }
        System.out.println();
        System.out.println("Consensus Validity: " + validity);
    }
}