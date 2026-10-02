use std::collections::{HashSet, VecDeque};

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue: VecDeque<(String, Vec<String>)> = VecDeque::new();
    queue.push_back((start.to_string(), vec![start.to_string()]));
    let mut visited: HashSet<String> = HashSet::new();

    while let Some((node, path)) = queue.pop_front() {
        if node == end {
            return path;
        }
        if !visited.contains(&node) {
            visited.insert(node.clone());
            for neighbor in &graph[&node] {
                let mut new_path = path.clone();
                new_path.push(neighbor.to_string());
                queue.push_back((neighbor.to_string(), new_path));
            }
        }
    }
    Vec::new()
}

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    bfs(graph, start, end)
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec![]);
    graph.insert("E", vec!["F"]);
    graph.insert("F", vec![]);

    let start_node = "A";
    let end_node = "F";
    let path = find_shortest_path(&graph, start_node, end_node);
    println!("{:?}", path);
}