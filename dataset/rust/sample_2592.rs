use std::collections::{HashSet, VecDeque};

fn bfs_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut queue = VecDeque::new();
    queue.push_back((start, vec![start]));
    let mut visited = HashSet::new();
    while let Some((node, path)) = queue.pop_front() {
        if node == end {
            return Some(path);
        }
        if visited.insert(node) {
            for &neighbor in &graph[node] {
                if !visited.contains(neighbor) {
                    let mut new_path = path.clone();
                    new_path.push(neighbor);
                    queue.push_back((neighbor, new_path));
                }
            }
        }
    }
    None
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec![]);
    graph.insert("E", vec!["F"]);
    graph.insert("F", vec![]);
    let start = "A";
    let end = "F";
    if let Some(path) = bfs_shortest_path(&graph, start, end) {
        println!("{}", path.join(" -> "));
    } else {
        println!("No path found");
    }
}