public class sample_1248 {
    public static void main(String[] args) {
        double gamma = 0.99;
        double[] rewards = {100, 50, 25, 10, 5};
        double state_value = 0;
        for (double r : rewards) {
            state_value = gamma * state_value + r;
        }
        System.out.println(state_value);
    }
}