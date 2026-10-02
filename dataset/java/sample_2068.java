import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2068 {
    public static void main(String[] args) {
        List<Double> nodes = generateNodes(10);
        int precision = 5;
        ConsensusMechanism mechanism = new ConsensusMechanism(nodes, precision);
        int result = mechanism.run();
        System.out.println(result);
    }

    static class ConsensusMechanism {
        private List<Double> nodes;
        private int precision;
        private boolean convergence;
        private int iterations;

        public ConsensusMechanism(List<Double> nodes, int precision) {
            this.nodes = nodes;
            this.precision = precision;
            this.convergence = false;
            this.iterations = 0;
        }

        public void updateState() {
            this.iterations += 1;
            List<Double> newValues = new ArrayList<>();
            for (Double node : nodes) {
                double newValue = calculateNewValue(node);
                newValues.add(newValue);
            }
            this.nodes = newValues;
        }

        public double calculateNewValue(Double node) {
            double total = 0.0;
            for (Double otherNode : nodes) {
                total += otherNode;
            }
            double average = total / nodes.size();
            return Math.round(average * Math.pow(10, precision)) / Math.pow(10, precision);
        }

        public boolean checkConvergence() {
            for (int i = 0; i < nodes.size() - 1; i++) {
                if (Math.abs(nodes.get(i) - nodes.get(i + 1)) > Math.pow(10, -precision)) {
                    return false;
                }
            }
            this.convergence = true;
            return true;
        }

        public int run() {
            while (!this.convergence) {
                updateState();
                checkConvergence();
            }
            return this.iterations;
        }
    }

    public static List<Double> generateNodes(int numNodes) {
        Random random = new Random();
        List<Double> nodes = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            nodes.add(random.nextDouble() * 100);
        }
        return nodes;
    }
}