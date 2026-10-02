public class sample_2993 {

    static class SequenceGenerator {
        int current;
        int increment;

        SequenceGenerator(int initial_value, int increment) {
            this.current = initial_value;
            this.increment = increment;
        }

        int next_value() {
            this.current += this.increment;
            return this.current;
        }
    }

    static class DemandOptimizer {
        SequenceGenerator sequence;
        int demand;

        DemandOptimizer(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.demand = 0;
        }

        void update_demand(int new_demand) {
            this.demand = new_demand;
        }

        int optimize() {
            int supply = this.sequence.next_value();
            return supply - this.demand;
        }
    }

    static class LogisticsController {
        DemandOptimizer optimizer;

        LogisticsController(DemandOptimizer optimizer) {
            this.optimizer = optimizer;
        }

        void run() {
            while (true) {
                int new_demand = this.optimizer.sequence.next_value() / 2;
                this.optimizer.update_demand(new_demand);
                int adjustment = this.optimizer.optimize();
                System.out.println("Adjustment: " + adjustment);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator sequence = new SequenceGenerator(100, 10);
        DemandOptimizer optimizer = new DemandOptimizer(sequence);
        LogisticsController controller = new LogisticsController(optimizer);
        controller.run();
    }
}