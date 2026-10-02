use std::collections::{BinaryHeap, HashSet};

fn dijkstra(graph: &std::collections::HashMap<char, Vec<(char, f64)>>, start: char, end: char) -> (f64, Vec<char>) {
    let mut q = BinaryHeap::new();
    q.push((0.0, start, Vec::new()));
    let mut visited = HashSet::new();

    while let Some((cost, v, path)) = q.pop() {
        if !visited.contains(&v) {
            visited.insert(v);
            let mut path = path.clone();
            path.push(v);
            if v == end {
                return (cost, path);
            }
            for &(next, c) in &graph[&v] {
                if !visited.contains(&next) {
                    q.push((cost + c, next, path.clone()));
                }
            }
        }
    }

    (f64::INFINITY, Vec::new())
}

fn find_shortest_path(graph: &std::collections::HashMap<char, Vec<(char, f64)>>, start: char, end: char) -> (f64, Vec<char>) {
    dijkstra(graph, start, end)
}

fn main() {
    let graph = {
        let mut g = std::collections::HashMap::new();
        g.insert('A', vec![('B', 1.0), ('C', 4.0)]);
        g.insert('B', vec![('C', 2.0), ('D', 5.0)]);
        g.insert('C', vec![('D', 1.0)]);
        g.insert('D', Vec::new());
        g
    };

    let start = 'A';
    let end = 'D';
    let (cost, path) = find_shortest_path(&graph, start, end);
    println!("Shortest path cost: {}", cost);
    println!("Shortest path: {:?}", path);
}