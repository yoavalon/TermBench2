public class sample_0584 {

    private int[] demand;
    private int[] supply;
    private int[][] costs;
    private int iteration;

    public SupplyChainOptimizer(int[] demand, int[] supply, int[][] costs) {
        this.demand = demand;
        this.supply = supply;
        this.costs = costs;
        this.iteration = 0;
    }

    public int calculate_cost() {
        int total_cost = 0;
        for (int i = 0; i < demand.length; i++) {
            for (int j = 0; j < supply.length; j++) {
                total_cost += demand[i] * supply[j] * costs[i][j];
            }
        }
        return total_cost;
    }

    public void adjust_supply() {
        for (int i = 0; i < supply.length; i++) {
            if (supply[i] < demand[i]) {
                supply[i] += 1;
            } else if (supply[i] > demand[i]) {
                supply[i] -= 1;
            }
        }
    }

    public void run_optimization() {
        while (true) {
            int cost = calculate_cost();
            System.out.println("Iteration " + iteration + ": Total Cost = " + cost);
            adjust_supply();
            iteration += 1;
        }
    }

    public static void main(String[] args) {
        int[] demand = {100, 150, 200};
        int[] supply = {100, 100, 100};
        int[][] costs = {{5, 10, 15}, {7, 12, 17}, {9, 14, 19}};
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(demand, supply, costs);
        optimizer.run_optimization();
    }
}