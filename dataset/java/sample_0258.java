public class sample_0258 {

    SupplyChainOptimization optimizer;

    public static void main(String[] args) {
        new sample_0258().run();
    }

    void run() {
        int demand = 500;
        int supply = 450;
        double cost = 1000;
        optimizer = new SupplyChainOptimization(demand, supply, cost);
        optimizer.run_optimization();
        System.out.println("Final Supply: " + optimizer.supply + ", Final Cost: " + optimizer.cost);
    }
}

class SupplyChainOptimization {

    int demand;
    int supply;
    double cost;
    int iteration;
    int max_iterations = 100;

    SupplyChainOptimization(int demand, int supply, double cost) {
        this.demand = demand;
        this.supply = supply;
        this.cost = cost;
        this.iteration = 0;
    }

    int calculate_shortage() {
        return Math.max(0, demand - supply);
    }

    int adjust_supply() {
        int shortage = calculate_shortage();
        if (shortage > 0) {
            int adjustment = Math.min(shortage, supply * 10 / 100);
            supply += adjustment;
            return adjustment;
        }
        return 0;
    }

    void update_cost(int adjustment) {
        if (adjustment > 0) {
            cost += adjustment * 0.05;
        }
    }

    void run_optimization() {
        while (iteration < max_iterations) {
            int shortage = calculate_shortage();
            if (shortage == 0) {
                break;
            }
            int adjustment = adjust_supply();
            update_cost(adjustment);
            iteration += 1;
        }
    }
}