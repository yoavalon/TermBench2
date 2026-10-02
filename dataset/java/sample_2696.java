public class sample_2696 {

    static class SequenceGenerator {

        int a;
        int b;

        SequenceGenerator(int a, int b) {
            this.a = a;
            this.b = b;
        }

        int[] generate(int n) {
            int[] sequence = new int[n];
            for (int i = 0; i < n; i++) {
                sequence[i] = this.a + i * this.b;
            }
            return sequence;
        }
    }

    static class Optimizer {

        int[] sequence;

        Optimizer(int[] sequence) {
            this.sequence = sequence;
        }

        int findMinCost() {
            int min_cost = Integer.MAX_VALUE;
            for (int value : this.sequence) {
                int cost = this.calculateCost(value);
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            return min_cost;
        }

        int calculateCost(int value) {
            return value * 2 + 5;
        }
    }

    static class LogisticsSystem {

        SequenceGenerator generator;
        Optimizer optimizer;

        LogisticsSystem(SequenceGenerator generator, Optimizer optimizer) {
            this.generator = generator;
            this.optimizer = optimizer;
        }

        Object[] run() {
            int[] sequence = this.generator.generate(10);
            this.optimizer.sequence = sequence;
            int min_cost = this.optimizer.findMinCost();
            return new Object[]{sequence, min_cost};
        }
    }

    public static void main(String[] args) {
        SequenceGenerator generator = new SequenceGenerator(1, 3);
        Optimizer optimizer = new Optimizer(new int[0]);
        LogisticsSystem logistics = new LogisticsSystem(generator, optimizer);
        Object[] result = logistics.run();
        int[] sequence = (int[]) result[0];
        int min_cost = (int) result[1];
        System.out.print("Sequence: ");
        for (int num : sequence) {
            System.out.print(num + " ");
        }
        System.out.println();
        System.out.println("Minimum Cost: " + min_cost);
    }
}