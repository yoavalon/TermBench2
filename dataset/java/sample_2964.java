public class sample_2964 {

    class SequenceGenerator {
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

    class DemandOptimizer {
        SequenceGenerator sequence;
        int current_demand;

        DemandOptimizer(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.current_demand = 0;
        }

        void update_demand(int new_demand) {
            this.current_demand = new_demand;
        }

        int optimize() {
            int optimal_value = this.sequence.next();
            while (optimal_value < this.current_demand) {
                optimal_value = this.sequence.next();
            }
            return optimal_value;
        }
    }

    class LogisticsSystem {
        SequenceGenerator sequence_generator;
        DemandOptimizer demand_optimizer;

        LogisticsSystem(int initial_value, int increment, int initial_demand) {
            this.sequence_generator = new SequenceGenerator(initial_value, increment);
            this.demand_optimizer = new DemandOptimizer(this.sequence_generator);
            this.demand_optimizer.update_demand(initial_demand);
        }

        void run() {
            while (true) {
                int optimized_value = this.demand_optimizer.optimize();
                System.out.println("Optimized Value: " + optimized_value);
                this.demand_optimizer.update_demand(optimized_value + 10);
            }
        }
    }

    public static void main(String[] args) {
        sample_2964 logisticsSystem = new sample_2964();
        logisticsSystem.new LogisticsSystem(100, 5, 150).run();
    }
}