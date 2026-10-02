use std::collections::HashMap;
use std::collections::VecDeque;

fn bfs(graph: &HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    let mut queue = VecDeque::new();
    queue.push_back(start);
    let mut visited = HashMap::new();
    visited.insert(start, true);
    let mut distances = HashMap::new();
    distances.insert(start, 0);

    while let Some(node) = queue.pop_front() {
        if node == end {
            return *distances.get(node).unwrap();
        }
        if let Some(neighbors) = graph.get(node) {
            for neighbor in neighbors {
                if !visited.contains_key(neighbor) {
                    visited.insert(neighbor, true);
                    distances.insert(neighbor, *distances.get(node).unwrap() + 1);
                    queue.push_back(neighbor);
                }
            }
        }
    }
    -1
}

fn shortest_path(graph: &HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    bfs(graph, start, end)
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["A", "D", "E"]);
    graph.insert("C", vec!["A", "F"]);
    graph.insert("D", vec!["B"]);
    graph.insert("E", vec!["B", "F"]);
    graph.insert("F", vec!["C", "E"]);

    println!("{}", shortest_path(&graph, "A", "F"));
}