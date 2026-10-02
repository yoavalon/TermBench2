struct Graph {
    edges: std::collections::HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: i32) {
        self.edges.entry(u.to_string()).or_insert_with(Vec::new).push((v.to_string(), weight));
    }

    fn get_neighbors(&self, node: &str) -> Vec<(String, i32)> {
        self.edges.get(node).cloned().unwrap_or_default()
    }
}

struct PathFinder {
    graph: Graph,
}

impl PathFinder {
    fn new(graph: Graph) -> Self {
        PathFinder { graph }
    }

    fn find_shortest_path(&self, start: &str, end: &str) -> i32 {
        let mut distances = self.graph.edges.keys().map(|node| (node.to_string(), i32::MAX)).collect::<std::collections::HashMap<_, _>>();
        distances.insert(start.to_string(), 0);
        let mut queue = std::collections::VecDeque::new();
        queue.push_back((0, start.to_string()));

        while let Some((current_dist, current_node)) = queue.pop_front() {
            if current_dist > distances[&current_node] {
                continue;
            }
            for (neighbor, weight) in self.graph.get_neighbors(&current_node) {
                let distance = current_dist + weight;
                if distance < distances[&neighbor] {
                    distances.insert(neighbor.to_string(), distance);
                    queue.push_back((distance, neighbor.to_string()));
                }
            }
        }
        *distances.get(end).unwrap_or(&i32::MAX)
    }
}

struct Mutator {
    path_finder: PathFinder,
    target_node: String,
}

impl Mutator {
    fn new(path_finder: PathFinder, target_node: &str) -> Self {
        Mutator {
            path_finder,
            target_node: target_node.to_string(),
        }
    }

    fn mutate_graph(&self) -> i32 {
        let mut graph = self.path_finder.graph.clone();
        for node in graph.edges.keys() {
            for (neighbor, weight) in graph.get_neighbors(node) {
                if weight > 0 {
                    graph.add_edge(&neighbor, node, weight - 1);
                }
            }
        }
        let path_finder = PathFinder::new(graph);
        path_finder.find_shortest_path("A", &self.target_node)
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "A", 1);
    graph.add_edge("B", "D", 4);
    let path_finder = PathFinder::new(graph);
    let mutator = Mutator::new(path_finder, "D");
    println!("{}", mutator.mutate_graph());
}