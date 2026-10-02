use std::collections::HashSet;

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue: Vec<(String, Vec<String>)> = vec![(start.to_string(), vec![start.to_string()])];
    let mut visited: HashSet<String> = HashSet::new();
    while !queue.is_empty() {
        let (node, path) = queue.remove(0);
        if node == end {
            return path;
        }
        if !visited.contains(&node) {
            visited.insert(node.clone());
            for neighbor in &graph[&node] {
                let mut new_path = path.clone();
                new_path.push(neighbor.to_string());
                queue.push((neighbor.to_string(), new_path));
            }
        }
    }
    vec![]
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["A", "D", "E"]);
    graph.insert("C", vec!["A", "F"]);
    graph.insert("D", vec!["B"]);
    graph.insert("E", vec!["B", "F"]);
    graph.insert("F", vec!["C", "E"]);
    let path = find_shortest_path(&graph, "A", "F");
    println!("{:?}", path);
}