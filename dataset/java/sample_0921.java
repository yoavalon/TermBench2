import java.util.ArrayList;
import java.util.List;

public class sample_0921 {
    public static List<Integer> optimize_supply_chain(int[] cost, int index, List<Integer> path) {
        path.add(index);
        if (cost[index] == 0) {
            return path;
        }
        int next_index = cost[index] - 1;
        return optimize_supply_chain(cost, next_index, path);
    }

    public static void main(String[] args) {
        int[] cost = {3, 2, 4, 1, 0, 5};
        List<Integer> path = new ArrayList<>();
        List<Integer> result = optimize_supply_chain(cost, 0, path);
        System.out.println(result);
    }
}