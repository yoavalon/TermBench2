use rand::Rng;

struct SupplyChain {
    nodes: Vec<Node>,
    edges: Vec<Edge>,
}

impl SupplyChain {
    fn new(nodes: Vec<Node>, edges: Vec<Edge>) -> Self {
        SupplyChain { nodes, edges }
    }

    fn optimize(&mut self) -> Vec<Node> {
        for _ in 0..10 {
            self.update_costs();
            self.reallocate_resources();
        }
        self.get_best_path()
    }

    fn update_costs(&mut self) {
        let mut rng = rand::thread_rng();
        for edge in &mut self.edges {
            edge.cost = rng.gen_range(1..=10);
        }
    }

    fn reallocate_resources(&mut self) {
        let mut rng = rand::thread_rng();
        for node in &mut self.nodes {
            node.resource = rng.gen_range(0..=100);
        }
    }

    fn get_best_path(&self) -> Vec<Node> {
        let mut best_path = Vec::new();
        let mut current_node = self.nodes.choose(&mut rand::thread_rng()).unwrap().clone();
        for _ in 0..5 {
            best_path.push(current_node.clone());
            let neighbors: Vec<&Edge> = self.edges.iter().filter(|&e| e.start == current_node.id).collect();
            if let Some(&next_edge) = neighbors.iter().min_by_key(|&&e| e.cost) {
                if let Some(next_node) = self.nodes.iter().find(|&n| n.id == next_edge.end) {
                    current_node = next_node.clone();
                }
            }
        }
        best_path
    }
}

#[derive(Clone)]
struct Node {
    id: usize,
    resource: usize,
}

struct Edge {
    start: usize,
    end: usize,
    cost: usize,
}

fn main() {
    let nodes: Vec<Node> = (0..5).map(|i| Node { id: i, resource: 0 }).collect();
    let edges = vec![
        Edge { start: 0, end: 1, cost: 0 },
        Edge { start: 1, end: 2, cost: 0 },
        Edge { start: 2, end: 3, cost: 0 },
        Edge { start: 3, end: 4, cost: 0 },
        Edge { start: 4, end: 0, cost: 0 },
    ];
    let mut supply_chain = SupplyChain::new(nodes, edges);
    let best_path = supply_chain.optimize();
    for node in best_path {
        println!("{:?}", node);
    }
}