use rand::Rng;

struct SupplyChainNode {
    value: f64,
    next: Option<Box<SupplyChainNode>>,
}

struct SupplyChain {
    head: Option<Box<SupplyChainNode>>,
}

impl SupplyChain {
    fn new() -> Self {
        SupplyChain { head: None }
    }

    fn append(&mut self, value: i32) {
        let new_node = Box::new(SupplyChainNode {
            value: value as f64,
            next: None,
        });
        match self.head {
            None => {
                self.head = Some(new_node);
            }
            Some(ref mut current) => {
                while let Some(ref mut next) = current.next {
                    current = next;
                }
                current.next = Some(new_node);
            }
        }
    }

    fn optimize(&mut self) {
        let mut current = &mut self.head;
        while let Some(ref mut node) = current {
            node.value *= 1.05;
            current = &mut node.next;
        }
    }

    fn display(&self) {
        let mut current = &self.head;
        while let Some(ref node) = current {
            println!("{}", node.value);
            current = &node.next;
        }
    }
}

struct LogisticsOptimizer {
    supply_chain: SupplyChain,
}

impl LogisticsOptimizer {
    fn new() -> Self {
        LogisticsOptimizer {
            supply_chain: SupplyChain::new(),
        }
    }

    fn initialize_supply_chain(&mut self, size: usize) {
        let mut rng = rand::thread_rng();
        for _ in 0..size {
            self.supply_chain.append(rng.gen_range(100..=1000));
        }
    }

    fn run_optimization(&mut self) {
        loop {
            self.supply_chain.optimize();
            self.supply_chain.display();
        }
    }
}

fn main() {
    let mut optimizer = LogisticsOptimizer::new();
    optimizer.initialize_supply_chain(10);
    optimizer.run_optimization();
}