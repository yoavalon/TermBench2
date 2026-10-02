import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class sample_1224 {
    public static List<HashMap<String, Integer>> optimize_supply_chain(List<HashMap<String, Integer>> data) {
        for (int i = 0; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                if (data.get(i).get("cost") > data.get(j).get("cost")) {
                    HashMap<String, Integer> temp = data.get(i);
                    data.set(i, data.get(j));
                    data.set(j, temp);
                }
            }
        }
        return data;
    }

    public static void main(String[] args) {
        List<HashMap<String, Integer>> data = new ArrayList<>();
        HashMap<String, Integer> itemA = new HashMap<>();
        itemA.put("item", 50);
        itemA.put("cost", 50);
        data.add(itemA);

        HashMap<String, Integer> itemB = new HashMap<>();
        itemB.put("item", 50);
        itemB.put("cost", 30);
        data.add(itemB);

        HashMap<String, Integer> itemC = new HashMap<>();
        itemC.put("item", 50);
        itemC.put("cost", 40);
        data.add(itemC);

        List<HashMap<String, Integer>> result = optimize_supply_chain(data);
        System.out.println(result);
    }
}