use std::collections::VecDeque;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    let mut queue = VecDeque::from([(start, 0)]);
    let mut visited = std::collections::HashSet::new();
    while let Some((node, dist)) = queue.pop_front() {
        if node == end {
            return dist;
        }
        if visited.insert(node) {
            for &neighbor in &graph[node] {
                queue.push_back((neighbor, dist + 1));
            }
        }
    }
    -1
}

fn main() {
    let graph = std::collections::HashMap::from([
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec![]),
        ("E", vec!["F"]),
        ("F", vec![]),
    ]);
    let start = "A";
    let end = "F";
    println!("{}", bfs(&graph, start, end));
}