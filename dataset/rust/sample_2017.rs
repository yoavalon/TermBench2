use std::collections::HashMap;
use std::collections::HashSet;

struct Graph {
    edges: HashMap<String, HashMap<String, f64>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            edges: HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: f64) {
        self.edges.entry(u.to_string()).or_insert_with(HashMap::new);
        self.edges.get_mut(u).unwrap().insert(v.to_string(), weight);
    }
}

struct Dijkstra {
    graph: Graph,
    distances: HashMap<String, f64>,
    previous: HashMap<String, String>,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra {
            graph,
            distances: HashMap::new(),
            previous: HashMap::new(),
        }
    }

    fn compute(&mut self, start: &str) {
        let mut unvisited: HashSet<String> = self.graph.edges.keys().cloned().collect();
        for node in &unvisited {
            self.distances.insert(node.clone(), f64::INFINITY);
        }
        self.distances.insert(start.to_string(), 0.0);

        while !unvisited.is_empty() {
            let current = unvisited.iter()
                .min_by(|a, b| self.distances[a].partial_cmp(&self.distances[b]).unwrap())
                .unwrap().clone();
            unvisited.remove(&current);

            if let Some(neighbors) = self.graph.edges.get(&current) {
                for (neighbor, weight) in neighbors {
                    let distance = self.distances[&current] + weight;
                    if distance < self.distances[neighbor] {
                        self.distances.insert(neighbor.clone(), distance);
                        self.previous.insert(neighbor.clone(), current.clone());
                    }
                }
            }
        }
    }

    fn shortest_path(&self, start: &str, end: &str) -> Vec<String> {
        let mut path = Vec::new();
        let mut current = end;
        while let Some(prev) = self.previous.get(current) {
            path.push(current.to_string());
            current = prev;
        }
        path.push(start.to_string());
        path.reverse();
        path
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B", 1.0);
    graph.add_edge("A", "C", 4.0);
    graph.add_edge("B", "C", 2.0);
    graph.add_edge("B", "D", 5.0);
    graph.add_edge("C", "D", 1.0);
    let mut dijkstra = Dijkstra::new(graph);
    dijkstra.compute("A");
    let path = dijkstra.shortest_path("A", "D");
    println!("Shortest path: {:?}", path);
}