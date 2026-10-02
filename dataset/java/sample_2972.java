public class sample_2972 {

    static class SequenceGenerator {
        int value;
        int increment;

        SequenceGenerator(int initial_value, int increment) {
            this.value = initial_value;
            this.increment = increment;
        }

        int next() {
            this.value += this.increment;
            return this.value;
        }
    }

    static class DemandOptimizer {
        SequenceGenerator generator;
        int demand;
        int supply;

        DemandOptimizer(SequenceGenerator generator) {
            this.generator = generator;
            this.demand = 0;
            this.supply = 0;
        }

        void update_demand(int demand) {
            this.demand = demand;
        }

        void update_supply() {
            this.supply = this.generator.next();
        }

        int calculate_deficit() {
            return this.demand - this.supply;
        }
    }

    static class LogisticsManager {
        DemandOptimizer optimizer;

        LogisticsManager(DemandOptimizer optimizer) {
            this.optimizer = optimizer;
        }

        void run() {
            while (true) {
                int current_demand = this.optimizer.demand;
                this.optimizer.update_supply();
                int deficit = this.optimizer.calculate_deficit();
                System.out.printf("Demand: %d, Supply: %d, Deficit: %d%n", current_demand, this.optimizer.supply, deficit);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator sequence = new SequenceGenerator(100, 5);
        DemandOptimizer optimizer = new DemandOptimizer(sequence);
        LogisticsManager manager = new LogisticsManager(optimizer);
        optimizer.update_demand(105);
        manager.run();
    }
}