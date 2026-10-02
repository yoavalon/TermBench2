use std::collections::VecDeque;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut queue: VecDeque<(String, Vec<String>)> = VecDeque::new();
    queue.push_back((start.to_string(), vec![start.to_string()]));
    
    while let Some((node, path)) = queue.pop_front() {
        for neighbor in &graph[&node] {
            if !path.contains(neighbor) {
                if neighbor == end {
                    let mut full_path = path.clone();
                    full_path.push(neighbor.to_string());
                    return Some(full_path);
                }
                let mut new_path = path.clone();
                new_path.push(neighbor.to_string());
                queue.push_back((neighbor.to_string(), new_path));
            }
        }
    }
    None
}

fn process_graph() {
    let graph: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ]
    .iter()
    .cloned()
    .collect();
    
    let start = "A";
    let end = "F";
    
    loop {
        if let Some(path) = bfs(&graph, start, end) {
            println!("Path found: {:?}", path);
        }
    }
}

fn main() {
    process_graph();
}