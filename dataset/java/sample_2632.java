public class sample_2632 {

    static class SequenceGenerator {
        int current;
        int end;
        int step;

        SequenceGenerator(int start, int end, int step) {
            this.current = start;
            this.end = end;
            this.step = step;
        }

        boolean has_next() {
            return this.current < this.end;
        }

        Integer next() {
            if (this.has_next()) {
                int value = this.current;
                this.current += this.step;
                return value;
            }
            return null;
        }
    }

    static class StateSimulator {
        SequenceGenerator sequence;
        java.util.ArrayList<java.util.List<Integer>> states;

        StateSimulator(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.states = new java.util.ArrayList<>();
        }

        void simulate() {
            while (this.sequence.has_next()) {
                Integer temp = this.sequence.next();
                int pressure = temp * 15 / 10;
                int volume = temp * 2;
                this.states.add(java.util.Arrays.asList(temp, pressure, volume));
            }
        }
    }

    static class DataProcessor {
        StateSimulator simulator;

        DataProcessor(StateSimulator simulator) {
            this.simulator = simulator;
        }

        void process() {
            for (java.util.List<Integer> state : this.simulator.states) {
                System.out.println("Temperature: " + state.get(0) + ", Pressure: " + state.get(1) + ", Volume: " + state.get(2));
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator seq = new SequenceGenerator(100, 300, 50);
        StateSimulator sim = new StateSimulator(seq);
        sim.simulate();
        DataProcessor processor = new DataProcessor(sim);
        processor.process();
    }
}