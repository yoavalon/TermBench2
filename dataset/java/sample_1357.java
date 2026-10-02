import java.util.Arrays;

public class sample_1357 {
    public static int[] optimize_routes(int[][] data) {
        int[] costs = Arrays.stream(data).mapToInt(arr -> arr[0]).toArray();
        int[] optimal_indices = new int[data[0].length];
        for (int i = 0; i < optimal_indices.length; i++) {
            optimal_indices[i] = 0;
            for (int j = 1; j < data.length; j++) {
                if (data[j][i] < data[optimal_indices[i]][i]) {
                    optimal_indices[i] = j;
                }
            }
        }
        return optimal_indices;
    }

    public static int[] update_inventory(int[] routes, int[] inventory) {
        for (int route : routes) {
            inventory[route]--;
        }
        return inventory;
    }

    public static void main(String[] args) {
        int[][] data = {{5, 3, 8}, {2, 6, 4}, {7, 1, 9}};
        int[] inventory = {10, 10, 10};
        int[] routes = optimize_routes(data);
        int[] updated_inventory = update_inventory(routes, inventory);
        System.out.println(Arrays.toString(updated_inventory));
    }
}