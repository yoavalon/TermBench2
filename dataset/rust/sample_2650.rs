use std::collections::{HashMap, HashSet, BinaryHeap};
use std::cmp::Reverse;

struct Graph {
    nodes: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: i32) {
        let u = u.to_string();
        let v = v.to_string();
        self.nodes.entry(u).or_insert_with(Vec::new).push((v, weight));
    }

    fn get_neighbors(&self, node: &str) -> Vec<(String, i32)> {
        self.nodes.get(node).cloned().unwrap_or_else(Vec::new)
    }
}

fn dijkstra(graph: &Graph, start: &str, end: &str) -> (i32, Vec<String>) {
    let mut queue = BinaryHeap::new();
    queue.push(Reverse((0, start.to_string(), vec![])));
    let mut visited = HashSet::new();

    while let Some(Reverse((cost, node, path))) = queue.pop() {
        if !visited.contains(&node) {
            visited.insert(node.clone());
            let mut path = path.clone();
            path.push(node.clone());
            if node == end {
                return (cost, path);
            }
            for (neighbor, weight) in graph.get_neighbors(&node) {
                if !visited.contains(&neighbor) {
                    queue.push(Reverse((cost + weight, neighbor, path.clone())));
                }
            }
        }
    }
    (i32::MAX, vec![])
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 4);
    graph.add_edge("B", "C", 2);
    graph.add_edge("B", "D", 5);
    graph.add_edge("C", "D", 1);
    let (cost, path) = dijkstra(&graph, "A", "D");
    println!("Cost: {}, Path: {:?}", cost, path);
}