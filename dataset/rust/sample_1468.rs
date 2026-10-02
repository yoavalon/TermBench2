use std::collections::{HashMap, BinaryHeap};
use std::cmp::Reverse;

struct Graph {
    nodes: HashMap<i32, Vec<(i32, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_node(&mut self, node: i32) {
        if !self.nodes.contains_key(&node) {
            self.nodes.insert(node, Vec::new());
        }
    }

    fn add_edge(&mut self, from_node: i32, to_node: i32, weight: i32) {
        if let Some(edges) = self.nodes.get_mut(&from_node) {
            edges.push((to_node, weight));
        }
    }
}

fn dijkstra(graph: &Graph, start: i32, end: i32) -> i32 {
    let mut distances: HashMap<i32, i32> = graph.nodes.keys().map(|&node| (node, i32::MAX)).collect();
    distances.insert(start, 0);
    let mut priority_queue: BinaryHeap<(Reverse<i32>, i32)> = BinaryHeap::new();
    priority_queue.push((Reverse(0), start));

    while let Some((Reverse(current_distance), current_node)) = priority_queue.pop() {
        if current_distance > distances[&current_node] {
            continue;
        }
        if let Some(neighbors) = graph.nodes.get(&current_node) {
            for &(neighbor, weight) in neighbors {
                let distance = current_distance + weight;
                if distance < distances[&neighbor] {
                    distances.insert(neighbor, distance);
                    priority_queue.push((Reverse(distance), neighbor));
                }
            }
        }
    }
    *distances.get(&end).unwrap_or(&i32::MAX)
}

fn main() {
    let mut graph = Graph::new();
    graph.add_node(1);
    graph.add_node(2);
    graph.add_node(3);
    graph.add_node(4);
    graph.add_edge(1, 2, 10);
    graph.add_edge(1, 3, 15);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 4, 12);
    graph.add_edge(3, 4, 10);
    println!("{}", dijkstra(&graph, 1, 4));
}