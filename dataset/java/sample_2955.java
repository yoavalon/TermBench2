public class sample_2955 {
    static class ThermodynamicSimulation {
        int state;
        int rate;
        int threshold;

        ThermodynamicSimulation(int initial_state, int rate, int threshold) {
            this.state = initial_state;
            this.rate = rate;
            this.threshold = threshold;
        }

        void update_state() {
            this.state += this.rate;
            if (this.state > this.threshold) {
                this.state = this.threshold - (this.state - this.threshold);
            }
        }
    }

    static class SequenceGenerator {
        int value;
        int increment;

        SequenceGenerator(int start, int increment) {
            this.value = start;
            this.increment = increment;
        }

        int next_value() {
            this.value += this.increment;
            return this.value;
        }
    }

    static class Analysis {
        ThermodynamicSimulation simulation;
        SequenceGenerator generator;

        Analysis(ThermodynamicSimulation sim, SequenceGenerator gen) {
            this.simulation = sim;
            this.generator = gen;
        }

        void run() {
            while (true) {
                this.simulation.update_state();
                int val = this.generator.next_value();
                System.out.println("State: " + this.simulation.state + ", Value: " + val);
            }
        }
    }

    public static void main(String[] args) {
        ThermodynamicSimulation sim = new ThermodynamicSimulation(10, 2, 20);
        SequenceGenerator gen = new SequenceGenerator(0, 1);
        Analysis analysis = new Analysis(sim, gen);
        analysis.run();
    }
}