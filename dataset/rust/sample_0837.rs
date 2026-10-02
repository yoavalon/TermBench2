use std::collections::{HashMap, HashSet};

struct LogisticsOptimizer {
    data: HashMap<String, HashMap<String, i32>>,
}

impl LogisticsOptimizer {
    fn new(data: HashMap<String, HashMap<String, i32>>) -> Self {
        LogisticsOptimizer { data }
    }

    fn find_optimal_route(
        &self,
        current: &String,
        destination: &String,
        visited: &mut HashSet<String>,
    ) -> Option<Vec<String>> {
        if current == destination {
            return Some(vec![destination.clone()]);
        }
        visited.insert(current.clone());
        if let Some(neighbors) = self.data.get(current) {
            for neighbor in neighbors.keys() {
                if !visited.contains(neighbor) {
                    if let Some(mut path) = self.find_optimal_route(neighbor, destination, visited) {
                        path.insert(0, current.clone());
                        return Some(path);
                    }
                }
            }
        }
        None
    }

    fn calculate_cost(&self, path: &Vec<String>) -> i32 {
        let mut cost = 0;
        for i in 0..path.len() - 1 {
            if let Some(neighbors) = self.data.get(&path[i]) {
                if let Some(&edge_cost) = neighbors.get(&path[i + 1]) {
                    cost += edge_cost;
                } else {
                    return i32::MAX;
                }
            } else {
                return i32::MAX;
            }
        }
        cost
    }

    fn optimize(&self, start: &String, end: &String) -> (i32, Vec<String>) {
        let mut visited = HashSet::new();
        if let Some(path) = self.find_optimal_route(start, end, &mut visited) {
            let cost = self.calculate_cost(&path);
            (cost, path)
        } else {
            (i32::MAX, vec![])
        }
    }
}

fn main() {
    let mut data = HashMap::new();
    data.insert(
        "A".to_string(),
        vec![("B".to_string(), 10), ("C".to_string(), 15)]
            .into_iter()
            .collect(),
    );
    data.insert(
        "B".to_string(),
        vec![("A".to_string(), 10), ("D".to_string(), 20)]
            .into_iter()
            .collect(),
    );
    data.insert(
        "C".to_string(),
        vec![("A".to_string(), 15), ("D".to_string(), 30)]
            .into_iter()
            .collect(),
    );
    data.insert(
        "D".to_string(),
        vec![("B".to_string(), 20), ("C".to_string(), 30)]
            .into_iter()
            .collect(),
    );

    let optimizer = LogisticsOptimizer::new(data);
    let cost = optimizer.optimize(&"A".to_string(), &"D".to_string());
    println!("Optimal Cost: {}", cost.0);
    println!("Optimal Path: {:?}", cost.1);
}