struct Graph {
    nodes: Vec<String>,
    edges: std::collections::HashMap<String, std::collections::HashMap<String, i32>>,
}

impl Graph {
    fn new(nodes: Vec<String>) -> Self {
        Graph {
            nodes,
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: i32) {
        self.edges.entry(u.to_string()).or_insert_with(|| std::collections::HashMap::new()).insert(v.to_string(), weight);
    }

    fn get_neighbors(&self, node: &str) -> &std::collections::HashMap<String, i32> {
        self.edges.get(node).unwrap_or(&std::collections::HashMap::new())
    }
}

struct Dijkstra {
    graph: Graph,
    start: String,
    distances: std::collections::HashMap<String, i32>,
    priority_queue: Vec<(i32, String)>,
}

impl Dijkstra {
    fn new(graph: Graph, start: &str) -> Self {
        let mut distances = std::collections::HashMap::new();
        for node in &graph.nodes {
            distances.insert(node.clone(), i32::MAX);
        }
        distances.insert(start.to_string(), 0);
        Dijkstra {
            graph,
            start: start.to_string(),
            distances,
            priority_queue: vec![(0, start.to_string())],
        }
    }

    fn extract_min(&mut self) -> String {
        let mut min_distance = i32::MAX;
        let mut min_node = String::new();
        for (node, distance) in &self.priority_queue {
            if *distance < min_distance {
                min_distance = *distance;
                min_node = node.clone();
            }
        }
        self.priority_queue.retain(|&(d, ref n)| n != &min_node);
        min_node
    }

    fn update_distances(&mut self, current: &str, neighbors: &std::collections::HashMap<String, i32>) {
        for (neighbor, weight) in neighbors {
            let new_distance = self.distances[current] + weight;
            if new_distance < self.distances[neighbor] {
                self.distances.insert(neighbor.clone(), new_distance);
                self.priority_queue.push((new_distance, neighbor.clone()));
            }
        }
    }

    fn run(&mut self) -> std::collections::HashMap<String, i32> {
        while !self.priority_queue.is_empty() {
            let current = self.extract_min();
            let neighbors = self.graph.get_neighbors(&current);
            self.update_distances(&current, neighbors);
        }
        self.distances.clone()
    }
}

fn main() {
    let nodes = vec!["A".to_string(), "B".to_string(), "C".to_string(), "D".to_string(), "E".to_string()];
    let mut graph = Graph::new(nodes);
    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 4);
    graph.add_edge("B", "C", 2);
    graph.add_edge("B", "D", 5);
    graph.add_edge("C", "D", 1);
    graph.add_edge("D", "E", 3);
    let mut dijkstra = Dijkstra::new(graph, "A");
    let shortest_paths = dijkstra.run();
    println!("{:?}", shortest_paths);
}