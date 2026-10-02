use std::collections::{BinaryHeap, HashMap, HashSet};

fn initialize_graph(nodes: Vec<&str>, edges: Vec<(&str, &str, i32)>) -> HashMap<&str, Vec<(&str, i32)>> {
    let mut graph = HashMap::new();
    for &node in &nodes {
        graph.insert(node, Vec::new());
    }
    for (u, v, weight) in edges {
        graph.entry(u).or_insert_with(Vec::new).push((v, weight));
        graph.entry(v).or_insert_with(Vec::new).push((u, weight));
    }
    graph
}

fn find_shortest_path(graph: &HashMap<&str, Vec<(&str, i32)>>, start: &str, end: &str) -> (f64, Vec<&str>) {
    let mut queue = BinaryHeap::new();
    queue.push((0, start, Vec::new()));
    let mut visited = HashSet::new();
    while let Some((cost, node, path)) = queue.pop() {
        if visited.contains(&node) {
            continue;
        }
        let mut path = path.clone();
        path.push(node);
        visited.insert(node);
        if node == end {
            return (cost as f64, path);
        }
        for &(neighbor, weight) in &graph[node] {
            if !visited.contains(&neighbor) {
                queue.push((cost + weight, neighbor, path.clone()));
            }
        }
    }
    (f64::INFINITY, Vec::new())
}

fn main() {
    let nodes = vec!["A", "B", "C", "D", "E"];
    let edges = vec![
        ("A", "B", 1),
        ("B", "C", 2),
        ("C", "D", 3),
        ("D", "E", 4),
        ("E", "A", 5),
    ];
    let graph = initialize_graph(nodes, edges);
    let start = "A";
    let end = "E";
    let (cost, path) = find_shortest_path(&graph, start, end);
    println!("Cost: {}, Path: {:?}", cost, path);
}