public class sample_0175 {
    public static int optimize_supply_chain(int[][] data) {
        int[] demand = data[0];
        int[] supply = data[1];
        int[] cost = data[2];
        int total_cost = 0;
        for (int i = 0; i < demand.length; i++) {
            if (demand[i] <= supply[i]) {
                total_cost += demand[i] * cost[i];
                supply[i] -= demand[i];
            } else {
                total_cost += supply[i] * cost[i];
                demand[i] -= supply[i];
                supply[i] = 0;
            }
        }
        return total_cost;
    }

    public static int[][] process_data() {
        int[] demand = {100, 200, 150};
        int[] supply = {120, 180, 170};
        int[] cost = {10, 15, 20};
        return new int[][]{demand, supply, cost};
    }

    public static void main(String[] args) {
        int[][] data = process_data();
        int result = optimize_supply_chain(data);
        System.out.println(result);
    }
}