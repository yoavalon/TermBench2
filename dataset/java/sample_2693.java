public class sample_2693 {

    static class SequenceGenerator {
        int current;
        int end;
        int step;

        SequenceGenerator(int start, int end, int step) {
            this.current = start;
            this.end = end;
            this.step = step;
        }

        int[] generate() {
            int[] sequence = new int[(end - current) / step + 1];
            int index = 0;
            while (current <= end) {
                sequence[index++] = current;
                current += step;
            }
            return sequence;
        }
    }

    static class LogisticsOptimizer {
        int demand;
        int supply;

        LogisticsOptimizer(int demand, int supply) {
            this.demand = demand;
            this.supply = supply;
        }

        int calculate_deficit() {
            return Math.max(0, demand - supply);
        }

        int optimize() {
            int deficit = calculate_deficit();
            if (deficit > 0) {
                return supply + deficit;
            }
            return supply;
        }
    }

    public static void main(String[] args) {
        int[] demand_sequence = new SequenceGenerator(100, 200, 10).generate();
        int[] supply_sequence = new SequenceGenerator(120, 220, 15).generate();
        int[] optimized_supplies = new int[demand_sequence.length];
        for (int i = 0; i < demand_sequence.length; i++) {
            LogisticsOptimizer optimizer = new LogisticsOptimizer(demand_sequence[i], supply_sequence[i]);
            optimized_supplies[i] = optimizer.optimize();
        }
        for (int supply : optimized_supplies) {
            System.out.print(supply + " ");
        }
    }
}