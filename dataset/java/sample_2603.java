public class sample_2603 {

    static class SequenceGenerator {
        int a;
        int b;
        int n;
        int current;

        SequenceGenerator(int a, int b, int n) {
            this.a = a;
            this.b = b;
            this.n = n;
            this.current = a;
        }

        int generate_next() {
            if (current < n) {
                current += b;
                return current;
            }
            return -1;
        }
    }

    static class LogisticsOptimizer {
        SequenceGenerator sequence;
        int[] optimized;

        LogisticsOptimizer(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.optimized = new int[100]; // Arbitrary large size
        }

        int[] optimize() {
            int index = 0;
            while (true) {
                int next_value = sequence.generate_next();
                if (next_value == -1) {
                    break;
                }
                optimized[index++] = next_value;
            }
            return optimized;
        }
    }

    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        int n = 20;
        SequenceGenerator sequence = new SequenceGenerator(a, b, n);
        LogisticsOptimizer optimizer = new LogisticsOptimizer(sequence);
        int[] result = optimizer.optimize();
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}