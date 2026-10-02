import java.util.Random;

class Inventory {
    int stock;
    int replenish_rate;

    public Inventory(int initial_stock, int replenish_rate) {
        this.stock = initial_stock;
        this.replenish_rate = replenish_rate;
    }

    public void update_stock(double demand) {
        this.stock -= demand;
        if (this.stock < 0) {
            this.stock = 0;
        }
    }

    public void replenish() {
        this.stock += this.replenish_rate;
    }
}

class DemandGenerator {
    public double generate() {
        Random random = new Random();
        return 1 + (10 - 1) * random.nextDouble();
    }
}

class SupplyChainOptimizer {
    Inventory inventory;
    DemandGenerator demand_generator;

    public SupplyChainOptimizer(Inventory inventory, DemandGenerator demand_generator) {
        this.inventory = inventory;
        this.demand_generator = demand_generator;
    }

    public void run_optimization() {
        while (true) {
            double demand = demand_generator.generate();
            inventory.update_stock(demand);
            inventory.replenish();
        }
    }
}

public class sample_2375 {
    public static void main(String[] args) {
        int initial_stock = 100;
        int replenish_rate = 10;
        Inventory inventory = new Inventory(initial_stock, replenish_rate);
        DemandGenerator demand_generator = new DemandGenerator();
        SupplyChainOptimizer optimizer = new SupplyChainOptimizer(inventory, demand_generator);
        optimizer.run_optimization();
    }
}