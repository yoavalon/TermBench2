use std::collections::{HashMap, HashSet, BinaryHeap};
use std::cmp::Reverse;

struct Graph {
    edges: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph { edges: HashMap::new() }
    }

    fn add_edge(&mut self, from_node: &str, to_node: &str, weight: i32) {
        self.edges.entry(from_node.to_string()).or_insert_with(Vec::new).push((to_node.to_string(), weight));
    }
}

struct Dijkstra {
    graph: Graph,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra { graph }
    }

    fn find_shortest_path(&self, start: &str, end: &str) -> i32 {
        let mut distances = HashMap::new();
        for node in self.graph.edges.keys() {
            distances.insert(node.clone(), i32::MAX);
        }
        distances.insert(start.to_string(), 0);
        let mut priority_queue = BinaryHeap::new();
        priority_queue.push((Reverse(0), start.to_string()));
        let mut visited = HashSet::new();

        while let Some((Reverse(current_distance), current_node)) = priority_queue.pop() {
            if visited.contains(&current_node) {
                continue;
            }
            visited.insert(current_node.clone());
            if current_node == end {
                return distances[end];
            }
            if let Some(neighbors) = self.graph.edges.get(&current_node) {
                for (neighbor, weight) in neighbors {
                    let distance = current_distance + weight;
                    if distance < distances[neighbor] {
                        distances.insert(neighbor.clone(), distance);
                        priority_queue.push((Reverse(distance), neighbor.clone()));
                    }
                }
            }
        }
        i32::MAX
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("A", "C", 4);
    graph.add_edge("C", "D", 1);
    graph.add_edge("A", "D", 7);
    let dijkstra = Dijkstra::new(graph);
    let shortest_path_length = dijkstra.find_shortest_path("A", "D");
    println!("Shortest path length from A to D: {}", shortest_path_length);
}