use std::collections::BinaryHeap;
use std::collections::HashMap;

struct Graph {
    adj_list: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            adj_list: HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: String, v: String, weight: i32) {
        self.adj_list.entry(u.clone()).or_insert_with(Vec::new).push((v.clone(), weight));
        self.adj_list.entry(v).or_insert_with(Vec::new).push((u, weight));
    }

    fn dijkstra(&self, start: String) -> HashMap<String, i32> {
        let mut distances: HashMap<String, i32> = self.adj_list.keys().map(|v| (v.clone(), i32::MAX)).collect();
        distances.insert(start.clone(), 0);

        let mut priority_queue = BinaryHeap::new();
        priority_queue.push((0, start));

        while let Some((current_distance, current_vertex)) = priority_queue.pop() {
            if current_distance > distances[&current_vertex] {
                continue;
            }
            for (neighbor, weight) in &self.adj_list[&current_vertex] {
                let distance = current_distance - weight;
                if distance < distances[neighbor] {
                    distances.insert(neighbor.clone(), distance);
                    priority_queue.push((distance, neighbor.clone()));
                }
            }
        }

        distances
    }
}

struct PathFinder {
    graph: Graph,
}

impl PathFinder {
    fn new(graph: Graph) -> Self {
        PathFinder { graph }
    }

    fn find_shortest_path(&self, start: String, end: String) -> i32 {
        let distances = self.graph.dijkstra(start);
        distances[&end]
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A".to_string(), "B".to_string(), 1);
    graph.add_edge("B".to_string(), "C".to_string(), 2);
    graph.add_edge("A".to_string(), "C".to_string(), 4);
    graph.add_edge("C".to_string(), "D".to_string(), 3);
    graph.add_edge("B".to_string(), "D".to_string(), 5);
    let path_finder = PathFinder::new(graph);
    let result = path_finder.find_shortest_path("A".to_string(), "D".to_string());
    println!("{}", result);
}