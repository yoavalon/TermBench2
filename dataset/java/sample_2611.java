public class sample_2611 {

    static class SequenceGenerator {
        int current;
        int increment;

        SequenceGenerator(int start, int increment) {
            this.current = start;
            this.increment = increment;
        }

        int[] generate(int count) {
            int[] sequence = new int[count];
            for (int i = 0; i < count; i++) {
                sequence[i] = this.current;
                this.current += this.increment;
            }
            return sequence;
        }
    }

    static class SupplyChainOptimizer {
        int demand;
        int supply;

        SupplyChainOptimizer(int demand, int supply) {
            this.demand = demand;
            this.supply = supply;
        }

        int calculateDeficit() {
            int deficit = this.demand - this.supply;
            return Math.max(deficit, 0);
        }

        void optimizeSupply(int additionalSupply) {
            this.supply += additionalSupply;
        }
    }

    static class SupplyChain {
        int[] demand_sequence;
        int[] supply_sequence;
        SupplyChainOptimizer optimizer;

        SupplyChain(int[] demand_sequence, int[] supply_sequence) {
            this.demand_sequence = demand_sequence;
            this.supply_sequence = supply_sequence;
            this.optimizer = new SupplyChainOptimizer(0, 0);
        }

        void runOptimization() {
            for (int i = 0; i < demand_sequence.length; i++) {
                int demand = demand_sequence[i];
                int supply = supply_sequence[i];
                optimizer.supply = supply;
                int deficit = optimizer.calculateDeficit();
                if (deficit > 0) {
                    int additionalSupply = new SequenceGenerator(deficit, 1).generate(1)[0];
                    optimizer.optimizeSupply(additionalSupply);
                }
                System.out.printf("Demand: %d, Supply: %d, Deficit: %d, Adjusted Supply: %d%n", demand, supply, deficit, optimizer.supply);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator demand_gen = new SequenceGenerator(100, 10);
        int[] demand_sequence = demand_gen.generate(10);
        SequenceGenerator supply_gen = new SequenceGenerator(80, 5);
        int[] supply_sequence = supply_gen.generate(10);
        SupplyChain supply_chain = new SupplyChain(demand_sequence, supply_sequence);
        supply_chain.runOptimization();
    }
}