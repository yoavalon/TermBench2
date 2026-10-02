use std::collections::{HashSet, VecDeque};

fn bfs(graph: &std::collections::HashMap<&str, HashSet<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut queue: VecDeque<(String, Vec<String>)> = VecDeque::new();
    queue.push_back((start.to_string(), vec![start.to_string()]));
    let mut visited: HashSet<String> = HashSet::new();
    while let Some((node, path)) = queue.pop_front() {
        if node == end {
            return Some(path);
        }
        visited.insert(node.clone());
        for neighbor in &graph[&node] {
            if !visited.contains(neighbor) {
                let mut new_path = path.clone();
                new_path.push(neighbor.to_string());
                queue.push_back((neighbor.to_string(), new_path));
            }
        }
    }
    None
}

fn main() {
    let mut graph: std::collections::HashMap<&str, HashSet<&str>> = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"].into_iter().collect());
    graph.insert("B", vec!["A", "D", "E"].into_iter().collect());
    graph.insert("C", vec!["A", "F"].into_iter().collect());
    graph.insert("D", vec!["B"].into_iter().collect());
    graph.insert("E", vec!["B", "F"].into_iter().collect());
    graph.insert("F", vec!["C", "E"].into_iter().collect());
    let start_node = "A";
    let end_node = "F";
    match bfs(&graph, start_node, end_node) {
        Some(result) => println!("{:?}", result),
        None => println!("No path found"),
    }
}