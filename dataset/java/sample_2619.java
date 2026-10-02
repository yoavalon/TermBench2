import java.util.ArrayList;
import java.util.List;

public class sample_2619 {
    static class SequenceGenerator {
        private int current;
        private int stop;
        private int step;

        public SequenceGenerator(int start, int stop, int step) {
            this.current = start;
            this.stop = stop;
            this.step = step;
        }

        public Iterable<Integer> generate() {
            return new Iterable<Integer>() {
                public java.util.Iterator<Integer> iterator() {
                    return new java.util.Iterator<Integer>() {
                        public boolean hasNext() {
                            return current < stop;
                        }

                        public Integer next() {
                            int value = current;
                            current += step;
                            return value;
                        }
                    };
                }
            };
        }
    }

    static class ThermodynamicSimulator {
        private SequenceGenerator sequence;
        private double temperature;

        public ThermodynamicSimulator(SequenceGenerator sequence) {
            this.sequence = sequence;
            this.temperature = 300;
        }

        public Iterable<Double> simulate() {
            return new Iterable<Double>() {
                public java.util.Iterator<Double> iterator() {
                    return new java.util.Iterator<Double>() {
                        private Iterator<Integer> seqIterator = sequence.generate().iterator();

                        public boolean hasNext() {
                            return seqIterator.hasNext();
                        }

                        public Double next() {
                            int value = seqIterator.next();
                            temperature += value * 0.1;
                            return temperature;
                        }
                    };
                }
            };
        }
    }

    static class DataCollector {
        private ThermodynamicSimulator simulator;
        private List<Double> data;

        public DataCollector(ThermodynamicSimulator simulator) {
            this.simulator = simulator;
            this.data = new ArrayList<>();
        }

        public List<Double> collect() {
            for (double temp : simulator.simulate()) {
                data.add(temp);
            }
            return data;
        }
    }

    public static void main(String[] args) {
        int start = 0;
        int stop = 100;
        int step = 5;
        SequenceGenerator sequence = new SequenceGenerator(start, stop, step);
        ThermodynamicSimulator simulator = new ThermodynamicSimulator(sequence);
        DataCollector collector = new DataCollector(simulator);
        List<Double> result = collector.collect();
        System.out.println(result);
    }
}