use std::collections::{HashSet, VecDeque};

fn bfs_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, goal: &str) -> Option<Vec<&str>> {
    let mut queue = VecDeque::from([(start, vec![start])]);
    let mut visited = HashSet::new();
    while let Some((node, path)) = queue.pop_front() {
        if node == goal {
            return Some(path);
        }
        if !visited.contains(node) {
            visited.insert(node);
            for neighbor in &graph[node] {
                if !visited.contains(neighbor) {
                    let mut new_path = path.clone();
                    new_path.push(*neighbor);
                    queue.push_back((*neighbor, new_path));
                }
            }
        }
    }
    None
}

fn main() {
    let graph: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec!["G"]),
        ("E", vec!["F"]),
        ("F", vec!["G"]),
        ("G", vec![]),
    ].iter().cloned().collect();
    let start_node = "A";
    let goal_node = "G";
    if let Some(result) = bfs_shortest_path(&graph, start_node, goal_node) {
        println!("{:?}", result);
    }
}