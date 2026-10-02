public class sample_2090 {

    class ConsensusMechanic {
        double precision;
        double tolerance;
        int iteration_limit;
        boolean converged;
        double value;

        ConsensusMechanic(double precision) {
            this.precision = precision;
            this.tolerance = 1e-10;
            this.iteration_limit = 1000;
            this.converged = false;
            this.value = 0.0;
        }

        void update_value(double new_value) {
            this.value = new_value;
        }

        void check_convergence(double new_value) {
            double difference = Math.abs(new_value - this.value);
            if (difference < this.tolerance) {
                this.converged = true;
            } else {
                this.converged = false;
            }
        }

        double perform_consensus() {
            double current_value = 0.0;
            for (int i = 0; i < this.iteration_limit; i++) {
                current_value += this.precision;
                this.update_value(current_value);
                this.check_convergence(current_value);
                if (this.converged) {
                    break;
                }
            }
            return this.value;
        }
    }

    double simulate_decentralized_ledger() {
        ConsensusMechanic mechanic = new ConsensusMechanic(0.0001);
        double final_value = mechanic.perform_consensus();
        return final_value;
    }

    public static void main(String[] args) {
        sample_2090 sample = new sample_2090();
        double result = sample.simulate_decentralized_ledger();
        System.out.println(result);
    }
}