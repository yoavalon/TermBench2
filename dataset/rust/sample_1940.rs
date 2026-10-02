use std::collections::{HashMap, HashSet, BinaryHeap};
use std::cmp::Reverse;

fn initialize_graph(nodes: Vec<&str>, edges: Vec<(&str, &str, f64)>) -> HashMap<&str, Vec<(&str, f64)>> {
    let mut graph = HashMap::new();
    for node in nodes {
        graph.insert(node, Vec::new());
    }
    for (u, v, weight) in edges {
        graph.get_mut(u).unwrap().push((v, weight));
        graph.get_mut(v).unwrap().push((u, weight));
    }
    graph
}

fn dijkstra(graph: &HashMap<&str, Vec<(&str, f64)>>, start: &str, target: &str) -> (f64, Vec<&str>) {
    let mut queue = BinaryHeap::new();
    queue.push((Reverse(0.0), start, vec![]));
    let mut visited = HashSet::new();
    while let Some((Reverse(cost), node, path)) = queue.pop() {
        if !visited.contains(node) {
            visited.insert(node);
            let mut new_path = path.clone();
            new_path.push(node);
            if node == target {
                return (cost, new_path);
            }
            for (neighbor, weight) in &graph[node] {
                if !visited.contains(neighbor) {
                    queue.push((Reverse(cost + weight), neighbor, new_path.clone()));
                }
            }
        }
    }
    (f64::INFINITY, Vec::new())
}

fn main() {
    let nodes = vec!["A", "B", "C", "D", "E"];
    let edges = vec![
        ("A", "B", 1.0),
        ("B", "C", 2.5),
        ("C", "D", 1.0),
        ("D", "E", 1.5),
        ("A", "E", 4.0),
    ];
    let graph = initialize_graph(nodes, edges);
    let (cost, path) = dijkstra(&graph, "A", "E");
    println!("Shortest path cost: {}, Path: {:?}", cost, path);
}