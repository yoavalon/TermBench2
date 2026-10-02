public class sample_0615 {
    public static int optimize_supply_chain(int[][] costs, int index, int result) {
        if (index == costs.length) {
            return result;
        }
        int min_cost = Integer.MAX_VALUE;
        for (int cost : costs[index]) {
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        return optimize_supply_chain(costs, index + 1, result + min_cost);
    }

    public static void main(String[] args) {
        int[][] costs = {{10, 20, 30}, {15, 25, 35}, {5, 15, 25}};
        System.out.println(optimize_supply_chain(costs, 0, 0));
    }
}