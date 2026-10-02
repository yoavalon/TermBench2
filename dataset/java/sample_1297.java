import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1297 {

    public static List<Integer> optimize_supply_chain(List<Integer> data) {
        Random random = new Random(0);
        int[] demand = new int[data.size()];
        int[] supply = new int[data.size()];
        int[] mutations = new int[data.size()];

        for (int i = 0; i < data.size(); i++) {
            demand[i] = random.nextInt(401) + 100;
            supply[i] = random.nextInt(401) + 100;
            mutations[i] = demand[i] > supply[i] ? demand[i] - supply[i] : 0;
        }

        List<Integer> result = new ArrayList<>();
        for (int mutation : mutations) {
            result.add(mutation);
        }

        return result;
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(i);
        }

        List<Integer> result = optimize_supply_chain(data);
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}