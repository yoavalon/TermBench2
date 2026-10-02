import java.util.ArrayList;
import java.util.List;

public class sample_1210 {
    public static List<int[]> optimize_supply_chain(List<int[]> data) {
        if (data.isEmpty()) {
            return new ArrayList<>();
        }
        int cost = Integer.MAX_VALUE;
        List<int[]> route = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                int temp_cost = data.get(i)[0] + data.get(j)[1];
                if (temp_cost < cost) {
                    cost = temp_cost;
                    route.clear();
                    route.add(data.get(i));
                    route.add(data.get(j));
                }
            }
        }
        return route;
    }

    public static void main(String[] args) {
        List<int[]> data = new ArrayList<>();
        data.add(new int[]{10, 20});
        data.add(new int[]{15, 25});
        data.add(new int[]{5, 30});
        data.add(new int[]{20, 10});
        List<int[]> result = optimize_supply_chain(data);
        System.out.println(result);
    }
}