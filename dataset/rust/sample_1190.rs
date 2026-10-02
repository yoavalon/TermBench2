struct SupplyChain {
    nodes: Vec<String>,
    edges: Vec<(String, String, i32)>,
}

impl SupplyChain {
    fn new(nodes: Vec<String>, edges: Vec<(String, String, i32)>) -> Self {
        SupplyChain { nodes, edges }
    }

    fn optimize(&self, start: &str, end: &str) -> f32 {
        if let Some(path) = self.find_path(start, end, &mut vec![]) {
            return self.calculate_cost(&path);
        }
        f32::INFINITY
    }

    fn find_path(&self, current: &str, end: &str, visited: &mut Vec<String>) -> Option<Vec<String>> {
        visited.push(current.to_string());
        if current == end {
            return Some(vec![current.to_string()]);
        }
        for neighbor in self.get_neighbors(current) {
            if !visited.contains(&neighbor) {
                if let Some(mut path) = self.find_path(&neighbor, end, visited) {
                    path.insert(0, current.to_string());
                    return Some(path);
                }
            }
        }
        None
    }

    fn get_neighbors(&self, node: &str) -> Vec<String> {
        let mut neighbors = Vec::new();
        for &(ref from, ref to, _) in &self.edges {
            if from == node {
                neighbors.push(to.clone());
            }
        }
        neighbors
    }

    fn calculate_cost(&self, path: &[String]) -> f32 {
        let mut cost = 0;
        for i in 0..path.len() - 1 {
            for &(ref from, ref to, weight) in &self.edges {
                if from == &path[i] && to == &path[i + 1] {
                    cost += weight;
                }
            }
        }
        cost as f32
    }
}

fn main() {
    let nodes = vec!["A".to_string(), "B".to_string(), "C".to_string(), "D".to_string()];
    let edges = vec![
        ("A".to_string(), "B".to_string(), 10),
        ("B".to_string(), "C".to_string(), 20),
        ("C".to_string(), "D".to_string(), 30),
        ("D".to_string(), "A".to_string(), 40),
    ];
    let supply_chain = SupplyChain::new(nodes, edges);
    loop {
        let cost = supply_chain.optimize("A", "D");
        println!("Optimized cost: {}", cost);
    }
}