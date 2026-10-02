import java.util.Random;

public class sample_1628 {

    public static void initialize_environment(int[] env) {
        env[0] = 0;
        env[1] = 10;
        env[2] = 95;
    }

    public static void update_state(int[] env) {
        env[0] += 1;
        env[1] *= env[2] / 100.0;
    }

    public static void main(String[] args) {
        int[] env = new int[3];
        initialize_environment(env);
        while (true) {
            update_state(env);
            System.out.printf("State: %d, Reward: %.2f%n", env[0], env[1]);
        }
    }
}