use std::collections::VecDeque;
use std::collections::HashSet;

fn find_shortest_path(graph: &std::collections::HashMap<String, std::collections::HashMap<String, f64>>, start: &str, end: &str) -> i32 {
    let mut queue: VecDeque<(String, i32, HashSet<String>)> = VecDeque::new();
    queue.push_back((start.to_string(), 0, HashSet::from([start.to_string()])));

    while let Some((node, cost, visited)) = queue.pop_front() {
        if node == end {
            return cost;
        }
        if let Some(neighbors) = graph.get(&node) {
            for (neighbor, weight) in neighbors {
                if !visited.contains(neighbor) {
                    let mut new_visited = visited.clone();
                    new_visited.insert(neighbor.clone());
                    queue.push_back((neighbor.clone(), cost + weight as i32, new_visited));
                }
            }
        }
    }
    -1
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A".to_string(), std::collections::HashMap::from([("B".to_string(), 1.0), ("C".to_string(), 4.0)]));
    graph.insert("B".to_string(), std::collections::HashMap::from([("A".to_string(), 1.0), ("D".to_string(), 2.0)]));
    graph.insert("C".to_string(), std::collections::HashMap::from([("A".to_string(), 4.0), ("D".to_string(), 1.0)]));
    graph.insert("D".to_string(), std::collections::HashMap::from([("B".to_string(), 2.0), ("C".to_string(), 1.0)]));

    println!("{}", find_shortest_path(&graph, "A", "D"));
}