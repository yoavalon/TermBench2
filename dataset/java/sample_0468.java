import java.util.Random;

public class sample_0468 {
    public static Iterable<int[]> simulate_episode(double decay_factor) {
        return new Iterable<int[]>() {
            @Override
            public java.util.Iterator<int[]> iterator() {
                return new java.util.Iterator<int[]>() {
                    private double total_reward = 0;
                    private double current_reward = 1.0;
                    private int step = 0;

                    @Override
                    public boolean hasNext() {
                        return true; // Non-terminating behavior
                    }

                    @Override
                    public int[] next() {
                        step += 1;
                        total_reward += current_reward;
                        current_reward *= decay_factor;
                        return new int[]{(int) total_reward, step};
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        double decay_factor = 0.95;
        for (int[] result : simulate_episode(decay_factor)) {
            System.out.println("Step " + result[1] + ": Total Reward " + result[0]);
        }
    }
}