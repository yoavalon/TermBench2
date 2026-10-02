use rand::Rng;

struct Inventory {
    stock: i32,
    replenish_rate: i32,
}

impl Inventory {
    fn new(initial_stock: i32, replenish_rate: i32) -> Self {
        Inventory {
            stock: initial_stock,
            replenish_rate: replenish_rate,
        }
    }

    fn update_stock(&mut self, demand: f64) {
        self.stock -= demand as i32;
        if self.stock < 0 {
            self.stock = 0;
        }
    }

    fn replenish(&mut self) {
        self.stock += self.replenish_rate;
    }
}

struct DemandGenerator;

impl DemandGenerator {
    fn generate(&self) -> f64 {
        let mut rng = rand::thread_rng();
        rng.gen_range(1.0..=10.0)
    }
}

struct SupplyChainOptimizer {
    inventory: Inventory,
    demand_generator: DemandGenerator,
}

impl SupplyChainOptimizer {
    fn new(inventory: Inventory, demand_generator: DemandGenerator) -> Self {
        SupplyChainOptimizer {
            inventory,
            demand_generator,
        }
    }

    fn run_optimization(&mut self) {
        loop {
            let demand = self.demand_generator.generate();
            self.inventory.update_stock(demand);
            self.inventory.replenish();
        }
    }
}

fn main() {
    let initial_stock = 100;
    let replenish_rate = 10;
    let inventory = Inventory::new(initial_stock, replenish_rate);
    let demand_generator = DemandGenerator;
    let mut optimizer = SupplyChainOptimizer::new(inventory, demand_generator);
    optimizer.run_optimization();
}