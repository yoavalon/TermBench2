struct SupplyChainOptimizer {
    nodes: Vec<String>,
    edges: std::collections::HashMap<String, std::collections::HashMap<String, i32>>,
    demand: i32,
    optimized_path: Vec<String>,
}

impl SupplyChainOptimizer {
    fn new(nodes: Vec<String>, edges: std::collections::HashMap<String, std::collections::HashMap<String, i32>>, demand: i32) -> Self {
        SupplyChainOptimizer {
            nodes,
            edges,
            demand,
            optimized_path: Vec::new(),
        }
    }

    fn find_optimal_path(&self, start: &String, end: &String, path: Vec<String>) -> Option<Vec<String>> {
        let mut path = path.clone();
        path.push(start.clone());
        if start == end {
            return Some(path);
        }
        if !self.edges.contains_key(start) {
            return None;
        }
        let mut shortest: Option<Vec<String>> = None;
        for node in self.edges[start].keys() {
            if !path.contains(node) {
                if let Some(newpath) = self.find_optimal_path(node, end, path.clone()) {
                    if shortest.is_none() || newpath.len() < shortest.as_ref().unwrap().len() {
                        shortest = Some(newpath);
                    }
                }
            }
        }
        shortest
    }

    fn calculate_supply(&self, path: &Vec<String>) -> i32 {
        let mut supply = 0;
        for i in 0..path.len() - 1 {
            supply += self.edges[&path[i]][&path[i + 1]];
        }
        supply
    }

    fn optimize(&mut self) {
        for start in &self.nodes {
            for end in &self.nodes {
                if start != end {
                    if let Some(path) = self.find_optimal_path(start, end, Vec::new()) {
                        if self.demand <= self.calculate_supply(&path) {
                            self.optimized_path = path;
                            return;
                        }
                    }
                }
            }
        }
    }
}

fn main() {
    let nodes = vec!["A".to_string(), "B".to_string(), "C".to_string(), "D".to_string()];
    let edges: std::collections::HashMap<String, std::collections::HashMap<String, i32>> = [
        ("A".to_string(), [("B".to_string(), 10), ("C".to_string(), 5)].iter().cloned().collect()),
        ("B".to_string(), [("D".to_string(), 8)].iter().cloned().collect()),
        ("C".to_string(), [("D".to_string(), 12)].iter().cloned().collect()),
        ("D".to_string(), [].iter().cloned().collect()),
    ].iter().cloned().collect();
    let demand = 15;
    let mut optimizer = SupplyChainOptimizer::new(nodes, edges, demand);
    optimizer.optimize();
    println!("{:?}", optimizer.optimized_path);
}