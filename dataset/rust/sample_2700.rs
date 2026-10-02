use std::collections::HashMap;
use std::collections::HashSet;

struct Graph {
    nodes: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_node(&mut self, node: &str) {
        self.nodes.insert(node.to_string(), Vec::new());
    }

    fn add_edge(&mut self, node1: &str, node2: &str, weight: i32) {
        if self.nodes.contains_key(node1) && self.nodes.contains_key(node2) {
            self.nodes.get_mut(node1).unwrap().push((node2.to_string(), weight));
            self.nodes.get_mut(node2).unwrap().push((node1.to_string(), weight));
        }
    }
}

struct PathFinder {
    graph: Graph,
}

impl PathFinder {
    fn new(graph: Graph) -> Self {
        PathFinder { graph }
    }

    fn find_shortest_path(&self, start: &str, end: &str) -> Vec<String> {
        let mut queue: Vec<(String, i32)> = vec![(start.to_string(), 0)];
        let mut visited: HashSet<String> = HashSet::new();
        let mut paths: HashMap<String, Vec<String>> = HashMap::new();
        paths.insert(start.to_string(), Vec::new());

        while let Some((node, distance)) = queue.pop(0) {
            if node == end {
                return paths[&node].clone() + &[node.to_string()];
            }
            if !visited.contains(&node) {
                visited.insert(node.to_string());
                for (neighbor, weight) in &self.graph.nodes[&node] {
                    if !visited.contains(neighbor) {
                        queue.push((neighbor.to_string(), distance + weight));
                        paths.insert(neighbor.to_string(), paths[&node].clone() + &[node.to_string()]);
                    }
                }
            }
        }
        Vec::new()
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_node("A");
    g.add_node("B");
    g.add_node("C");
    g.add_node("D");
    g.add_node("E");
    g.add_node("F");
    g.add_node("G");
    g.add_edge("A", "B", 1);
    g.add_edge("A", "C", 4);
    g.add_edge("B", "C", 2);
    g.add_edge("B", "D", 5);
    g.add_edge("C", "D", 1);
    g.add_edge("C", "E", 3);
    g.add_edge("D", "E", 1);
    g.add_edge("D", "F", 8);
    g.add_edge("E", "F", 2);
    g.add_edge("E", "G", 2);
    g.add_edge("F", "G", 7);
    let pf = PathFinder::new(g);
    let path = pf.find_shortest_path("A", "G");
    println!("{:?}", path);
}