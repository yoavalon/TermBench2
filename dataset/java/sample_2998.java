public class sample_2998 {

    static class SequenceGenerator {
        int value;
        int step;

        SequenceGenerator(int initial_value, int step) {
            this.value = initial_value;
            this.step = step;
        }

        int next() {
            this.value += this.step;
            return this.value;
        }
    }

    static class ThermodynamicSimulator {
        SequenceGenerator sequence;
        double temperature;
        double pressure;

        ThermodynamicSimulator(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.temperature = 0.0;
            this.pressure = 1.0;
        }

        void update_state() {
            this.temperature += this.sequence.next() / 100.0;
            this.pressure += this.sequence.next() / 1000.0;
        }

        double[] get_state() {
            return new double[]{this.temperature, this.pressure};
        }
    }

    static class DataCollector {
        ThermodynamicSimulator simulator;
        double[][] data;

        DataCollector(ThermodynamicSimulator simulator) {
            this.simulator = simulator;
            this.data = new double[0][];
        }

        void collect() {
            double[] state = this.simulator.get_state();
            double[][] newData = new double[this.data.length + 1][];
            for (int i = 0; i < this.data.length; i++) {
                newData[i] = this.data[i];
            }
            newData[this.data.length] = state;
            this.data = newData;
        }

        void display() {
            for (double[] entry : this.data) {
                System.out.println(entry[0] + ", " + entry[1]);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq = new SequenceGenerator(1, 1);
        ThermodynamicSimulator sim = new ThermodynamicSimulator(seq);
        DataCollector collector = new DataCollector(sim);
        while (true) {
            sim.update_state();
            collector.collect();
            collector.display();
        }
    }
}