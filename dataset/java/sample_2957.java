import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2957 {

    public static class SequenceGenerator {
        private List<Integer> sequence;

        public SequenceGenerator() {
            this.sequence = new ArrayList<>();
            this.sequence.add(new Random().nextInt(10) + 1);
        }

        public int generate() {
            int lastValue = this.sequence.get(this.sequence.size() - 1);
            int nextValue = new Random().nextInt(5) - 2 + lastValue;
            this.sequence.add(nextValue);
            return nextValue;
        }
    }

    public static class RewardDecayer {
        private double baseReward;
        private double decayFactor;
        private double currentReward;

        public RewardDecayer(double baseReward) {
            this.baseReward = baseReward;
            this.decayFactor = 0.95;
            this.currentReward = baseReward;
        }

        public double decay() {
            this.currentReward *= this.decayFactor;
            return this.currentReward;
        }
    }

    public static class Analysis {
        private SequenceGenerator generator;
        private RewardDecayer decayer;

        public Analysis(SequenceGenerator generator, RewardDecayer decayer) {
            this.generator = generator;
            this.decayer = decayer;
        }

        public void evaluate() {
            double totalReward = 0;
            while (true) {
                int value = this.generator.generate();
                double reward = this.decayer.decay();
                totalReward += reward;
                System.out.printf("Value: %d, Reward: %.2f, Total Reward: %.2f%n", value, reward, totalReward);
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator generator = new SequenceGenerator();
        RewardDecayer decayer = new RewardDecayer(100);
        Analysis analysis = new Analysis(generator, decayer);
        analysis.evaluate();
    }
}