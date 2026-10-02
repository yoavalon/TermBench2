struct SupplyChainOptimizer {
    nodes: Vec<i32>,
    edges: Vec<Vec<(usize, i32)>>,
    demand: i32,
    path: Vec<usize>,
}

impl SupplyChainOptimizer {
    fn new(nodes: Vec<i32>, edges: Vec<Vec<(usize, i32)>>, demand: i32) -> Self {
        SupplyChainOptimizer {
            nodes,
            edges,
            demand,
            path: Vec::new(),
        }
    }

    fn optimize(&mut self) {
        self._find_path(0, 0, 0);
    }

    fn _find_path(&mut self, current_node: usize, current_cost: i32, current_demand: i32) -> bool {
        if current_node == self.nodes.len() - 1 {
            if current_demand == self.demand {
                self.path.insert(0, current_node);
                return true;
            }
            return false;
        }
        for (neighbor, cost) in &self.edges[current_node] {
            if self._find_path(*neighbor, current_cost + cost, current_demand + 1) {
                self.path.insert(0, current_node);
                return true;
            }
        }
        false
    }
}

struct DemandBalancer {
    optimizer: SupplyChainOptimizer,
}

impl DemandBalancer {
    fn new(nodes: Vec<i32>, edges: Vec<Vec<(usize, i32)>>, demand: i32) -> Self {
        DemandBalancer {
            optimizer: SupplyChainOptimizer::new(nodes, edges, demand),
        }
    }

    fn balance(&mut self) -> Vec<usize> {
        self.optimizer.optimize();
        self.optimizer.path.clone()
    }
}

fn main() {
    let nodes = vec![0, 1, 2, 3, 4];
    let edges = vec![
        vec![(1, 10), (2, 15)],
        vec![(3, 5)],
        vec![(3, 10)],
        vec![(4, 20)],
        vec![],
    ];
    let demand = 3;
    let mut balancer = DemandBalancer::new(nodes, edges, demand);
    let result = balancer.balance();
    println!("{:?}", result);
}