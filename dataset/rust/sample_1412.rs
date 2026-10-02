struct Graph {
    edges: std::collections::HashMap<String, std::collections::HashMap<String, i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, node1: &str, node2: &str, weight: i32) {
        self.edges.entry(node1.to_string()).or_insert_with(|| std::collections::HashMap::new()).insert(node2.to_string(), weight);
        self.edges.entry(node2.to_string()).or_insert_with(|| std::collections::HashMap::new()).insert(node1.to_string(), weight);
    }

    fn get_neighbors(&self, node: &str) -> &std::collections::HashMap<String, i32> {
        self.edges.get(node).unwrap_or(&std::collections::HashMap::new())
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
        let mut distances: std::collections::HashMap<String, i32> = self.graph.edges.keys().map(|node| (node.clone(), i32::MAX)).collect();
        distances.insert(start.to_string(), 0);
        let mut unvisited: Vec<String> = self.graph.edges.keys().cloned().collect();

        while !unvisited.is_empty() {
            let current = unvisited.iter().min_by_key(|&node| distances[&node]).unwrap().clone();
            unvisited.retain(|&node| node != current);
            if current == end {
                break;
            }
            for (neighbor, &weight) in self.graph.get_neighbors(&current) {
                let distance = distances[&current] + weight;
                if distance < distances[neighbor] {
                    distances.insert(neighbor.clone(), distance);
                }
            }
        }
        distances[end]
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_edge("A", "B", 1);
    g.add_edge("B", "C", 2);
    g.add_edge("C", "D", 3);
    g.add_edge("A", "D", 10);
    g.add_edge("B", "D", 4);
    let dijkstra = Dijkstra::new(g);
    let result = dijkstra.find_shortest_path("A", "D");
    println!("{}", result);
}