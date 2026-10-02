use std::collections::VecDeque;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    let mut queue = VecDeque::new();
    queue.push_back((start, vec![start]));
    while let Some((node, path)) = queue.pop_front() {
        for &neighbor in &graph[node] {
            if neighbor == end {
                return Some(path.iter().cloned().chain(std::iter::once(neighbor)).collect());
            } else if !path.contains(&neighbor) {
                queue.push_back((neighbor, path.iter().cloned().chain(std::iter::once(neighbor)).collect()));
            }
        }
    }
    None
}

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Option<Vec<&str>> {
    bfs(graph, start, end)
}

fn main() {
    let graph = vec![
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ].into_iter().collect();
    let start = "A";
    let end = "F";
    if let Some(path) = find_shortest_path(&graph, start, end) {
        println!("{}", path.join(" -> "));
    } else {
        println!("No path found");
    }
}