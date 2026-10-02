import java.util.Random;

class SequenceGenerator {

    int size;
    double[] sequence;

    public SequenceGenerator(int size) {
        this.size = size;
        this.sequence = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            sequence[i] = rand.nextDouble();
        }
    }

    public double[] generate() {
        return this.sequence;
    }
}

class RewardCalculator {

    double discount_factor;

    public RewardCalculator(double discount_factor) {
        this.discount_factor = discount_factor;
    }

    public double calculate(double[] sequence) {
        double reward = 0;
        for (int t = 0; t < sequence.length; t++) {
            reward += Math.pow(discount_factor, t) * sequence[t];
        }
        return reward;
    }
}

class SequenceAnalyzer {

    RewardCalculator reward_calculator;

    public SequenceAnalyzer(RewardCalculator reward_calculator) {
        this.reward_calculator = reward_calculator;
    }

    public double analyze(double[] sequence) {
        return this.reward_calculator.calculate(sequence);
    }
}

public class sample_2617 {

    public static void main(String[] args) {
        int size = 10;
        double discount_factor = 0.9;
        SequenceGenerator generator = new SequenceGenerator(size);
        RewardCalculator reward_calculator = new RewardCalculator(discount_factor);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(reward_calculator);
        double[] sequence = generator.generate();
        double reward = analyzer.analyze(sequence);
        System.out.println("Sequence: ");
        for (double value : sequence) {
            System.out.print(value + " ");
        }
        System.out.println("\nReward: " + reward);
    }
}