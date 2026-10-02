import java.util.ArrayList;
import java.util.List;

public class sample_0110 {

    public static List<Object> optimize_supply_chain(List<Object> data) {
        List<Object> processed_data = new ArrayList<>();
        for (Object item : data) {
            @SuppressWarnings("unchecked")
            int quantity = ((List<Object>) item).get(1) instanceof Integer ? (Integer) ((List<Object>) item).get(1) : 0;
            if (quantity > 0) {
                processed_data.add(item);
            }
        }
        return processed_data;
    }

    public static int[] analyze_boundaries(List<Object> data) {
        int min_quantity = Integer.MAX_VALUE;
        int max_quantity = Integer.MIN_VALUE;
        for (Object item : data) {
            @SuppressWarnings("unchecked")
            int quantity = ((List<Object>) item).get(1) instanceof Integer ? (Integer) ((List<Object>) item).get(1) : 0;
            if (quantity < min_quantity) {
                min_quantity = quantity;
            }
            if (quantity > max_quantity) {
                max_quantity = quantity;
            }
        }
        return new int[]{min_quantity, max_quantity};
    }

    public static void main(String[] args) {
        List<Object> supply_data = new ArrayList<>();
        supply_data.add(List.of("A", 10));
        supply_data.add(List.of("B", 0));
        supply_data.add(List.of("C", 25));
        List<Object> optimized_data = optimize_supply_chain(supply_data);
        int[] boundaries = analyze_boundaries(optimized_data);
        System.out.println("Minimum Quantity: " + boundaries[0] + ", Maximum Quantity: " + boundaries[1]);
    }
}