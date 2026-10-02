struct SupplyChainOptimizer {
    network: std::collections::HashMap<String, Vec<String>>,
}

impl SupplyChainOptimizer {
    fn new(network: std::collections::HashMap<String, Vec<String>>) -> Self {
        SupplyChainOptimizer { network }
    }

    fn optimize(&self, node: &str) -> Option<Vec<String>> {
        if !self.network.contains_key(node) {
            return None;
        }
        let neighbors = &self.network[node];
        let mut best_route = None;
        for neighbor in neighbors {
            if let Some(route) = self.optimize(neighbor) {
                if best_route.is_none() || route.len() < best_route.as_ref().unwrap().len() {
                    best_route = Some(route);
                }
            }
        }
        best_route
    }

    fn find_best_path(&self) -> Option<Vec<String>> {
        if let Some(&first_key) = self.network.keys().next() {
            self.optimize(&first_key)
        } else {
            None
        }
    }
}

struct RecursivePathFinder {
    graph: std::collections::HashMap<String, Vec<String>>,
}

impl RecursivePathFinder {
    fn new(graph: std::collections::HashMap<String, Vec<String>>) -> Self {
        RecursivePathFinder { graph }
    }

    fn find_path(&self, node: &str, destination: &str, path: Vec<String>) -> Option<Vec<String>> {
        let mut path = path;
        path.push(node.to_string());
        if node == destination {
            return Some(path);
        }
        if !self.graph.contains_key(node) {
            return None;
        }
        for neighbor in &self.graph[node] {
            if !path.contains(neighbor) {
                if let Some(newpath) = self.find_path(neighbor, destination, path.clone()) {
                    return Some(newpath);
                }
            }
        }
        None
    }
}

struct LogisticsSystem {
    supply_chain: SupplyChainOptimizer,
    path_finder: RecursivePathFinder,
}

impl LogisticsSystem {
    fn new() -> Self {
        LogisticsSystem {
            supply_chain: SupplyChainOptimizer::new(std::collections::HashMap::new()),
            path_finder: RecursivePathFinder::new(std::collections::HashMap::new()),
        }
    }

    fn update_network(&mut self, network: std::collections::HashMap<String, Vec<String>>) {
        self.supply_chain.network = network.clone();
        self.path_finder.graph = network;
    }

    fn optimize_logistics(&self) -> Option<Vec<String>> {
        self.supply_chain.find_best_path()
    }
}

fn main() {
    let mut logistics_system = LogisticsSystem::new();
    let network: std::collections::HashMap<String, Vec<String>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec!["G"]),
        ("E", vec!["H"]),
        ("F", vec!["I"]),
        ("G", vec!["J"]),
        ("H", vec!["K"]),
        ("I", vec!["L"]),
        ("J", vec!["M"]),
        ("K", vec!["N"]),
        ("L", vec!["O"]),
        ("M", vec!["P"]),
        ("N", vec!["Q"]),
        ("O", vec!["R"]),
        ("P", vec!["S"]),
        ("Q", vec!["T"]),
        ("R", vec!["U"]),
        ("S", vec!["V"]),
        ("T", vec!["W"]),
        ("U", vec!["X"]),
        ("V", vec!["Y"]),
        ("W", vec!["Z"]),
        ("X", vec!["A"]),
    ]
    .iter()
    .cloned()
    .map(|(k, v)| (k.to_string(), v.into_iter().map(|s| s.to_string()).collect()))
    .collect();
    logistics_system.update_network(network);
    if let Some(best_path) = logistics_system.optimize_logistics() {
        println!("{:?}", best_path);
    }
}