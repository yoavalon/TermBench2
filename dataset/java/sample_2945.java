import java.util.Random;

class SequenceGenerator {
    private double currentValue;
    private double step;
    private double decayFactor;

    public SequenceGenerator(double start, double step, double decayFactor) {
        this.currentValue = start;
        this.step = step;
        this.decayFactor = decayFactor;
    }

    public double generateNext() {
        this.currentValue += this.step;
        this.step *= this.decayFactor;
        return this.currentValue;
    }
}

class RewardEvaluator {
    private double threshold;

    public RewardEvaluator(double threshold) {
        this.threshold = threshold;
    }

    public double evaluate(double value) {
        return Math.max(0, value - this.threshold);
    }
}

class NonTerminatingSimulation {
    private SequenceGenerator sequenceGen;
    private RewardEvaluator rewardEval;

    public NonTerminatingSimulation(SequenceGenerator sequenceGen, RewardEvaluator rewardEval) {
        this.sequenceGen = sequenceGen;
        this.rewardEval = rewardEval;
    }

    public void run() {
        double totalReward = 0;
        while (true) {
            double nextValue = this.sequenceGen.generateNext();
            double reward = this.rewardEval.evaluate(nextValue);
            totalReward += reward;
            System.out.printf("Value: %.2f, Reward: %.2f, Total Reward: %.2f%n", nextValue, reward, totalReward);
        }
    }
}

public class sample_2945 {
    public static void main(String[] args) {
        Random random = new Random();
        int startValue = random.nextInt(10) + 1;
        double stepSize = random.nextDouble() * 1.5 + 0.5;
        double decayFactor = random.nextDouble() * 0.09 + 0.9;
        int threshold = random.nextInt(11) + 5;
        SequenceGenerator seqGen = new SequenceGenerator(startValue, stepSize, decayFactor);
        RewardEvaluator rewardEval = new RewardEvaluator(threshold);
        NonTerminatingSimulation simulation = new NonTerminatingSimulation(seqGen, rewardEval);
        simulation.run();
    }
}