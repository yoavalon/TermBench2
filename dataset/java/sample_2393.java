public class sample_2393 {

    static class LedgerConsensus {
        double precision;
        double state;

        LedgerConsensus(double precision) {
            this.precision = precision;
            this.state = 0.0;
        }

        void update_state(double value) {
            this.state += value / this.precision;
        }

        boolean validate_consensus(double threshold) {
            return Math.abs(this.state) > threshold;
        }
    }

    static class PrecisionController {
        double controller_precision;
        double control_value;

        PrecisionController(double controller_precision) {
            this.controller_precision = controller_precision;
            this.control_value = 0.0;
        }

        void adjust_precision(boolean consensus) {
            if (consensus) {
                this.control_value += 1.0 / this.controller_precision;
            } else {
                this.control_value -= 1.0 / this.controller_precision;
            }
        }
    }

    static class SystemMonitor {
        LedgerConsensus ledger;
        PrecisionController controller;

        SystemMonitor(LedgerConsensus ledger, PrecisionController controller) {
            this.ledger = ledger;
            this.controller = controller;
        }

        void monitor(double threshold) {
            while (true) {
                this.ledger.update_state(this.controller.control_value);
                if (this.ledger.validate_consensus(threshold)) {
                    this.controller.adjust_precision(true);
                } else {
                    this.controller.adjust_precision(false);
                }
            }
        }
    }

    public static void main(String[] args) {
        LedgerConsensus ledger = new LedgerConsensus(1000);
        PrecisionController controller = new PrecisionController(10);
        SystemMonitor monitor = new SystemMonitor(ledger, controller);
        monitor.monitor(0.01);
    }
}