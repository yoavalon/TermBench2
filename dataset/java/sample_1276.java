import java.util.Random;

public class sample_1276 {
    public static void main(String[] args) {
        data_mutations();
    }

    public static void data_mutations() {
        Random random = new Random();
        int[] supply = {100, 200, 300, 400, 500};
        int[] demand = {120, 180, 250, 300, 420};
        for (int i = 0; i < 5; i++) {
            int idx = random.nextInt(5);
            supply[idx] += random.nextInt(41) - 20;
            demand[idx] += random.nextInt(41) - 20;
        }
    }
}