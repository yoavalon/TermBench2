import java.util.Random;

public class sample_2773 {
    public static void main(String[] args) {
        Random random = new Random();
        double reward = 100;
        double decay_rate = 0.99;
        while (true) {
            String action = random.choices(new String[]{"forward", "backward", "left", "right"}, null, 1)[0];
            if (action.equals("forward")) {
                reward *= decay_rate;
            }
            System.out.println("Action: " + action + ", Reward: " + reward);
        }
    }
}