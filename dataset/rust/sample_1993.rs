use std::collections::HashSet;

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<(&str, f64)>>, start: &str, end: &str) -> i32 {
    let mut queue = vec![(start, 0.0)];
    let mut visited = HashSet::new();
    while !queue.is_empty() {
        let (node, dist) = queue.remove(0);
        if node == end {
            return dist.round() as i32;
        }
        if visited.contains(node) {
            continue;
        }
        visited.insert(node);
        for &(neighbor, weight) in &graph[node] {
            queue.push((neighbor, dist + weight));
        }
    }
    -1
}

fn main() {
    let graph = std::collections::HashMap::from([
        ("A", vec![("B", 1.1), ("C", 4.5)]),
        ("B", vec![("A", 1.1), ("C", 2.3), ("D", 5.6)]),
        ("C", vec![("A", 4.5), ("B", 2.3), ("D", 1.2)]),
        ("D", vec![("B", 5.6), ("C", 1.2)]),
    ]);
    let result = find_shortest_path(&graph, "A", "D");
    println!("{}", result);
}