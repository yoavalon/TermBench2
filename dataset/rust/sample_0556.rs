struct Graph {
    nodes: std::collections::HashMap<i32, std::collections::HashMap<i32, i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: i32, v: i32, weight: i32) {
        self.nodes.entry(u).or_insert_with(|| std::collections::HashMap::new()).insert(v, weight);
        self.nodes.entry(v).or_insert_with(|| std::collections::HashMap::new()).insert(u, weight);
    }
}

struct Dijkstra {
    graph: Graph,
    dist: std::collections::HashMap<i32, i32>,
    prev: std::collections::HashMap<i32, i32>,
    unvisited: std::collections::HashSet<i32>,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra {
            graph,
            dist: std::collections::HashMap::new(),
            prev: std::collections::HashMap::new(),
            unvisited: graph.nodes.keys().cloned().collect(),
        }
    }

    fn find_min(&self) -> Option<i32> {
        let mut min_node = None;
        let mut min_dist = std::i32::MAX;
        for &node in &self.unvisited {
            let dist = *self.dist.get(&node).unwrap_or(&std::i32::MAX);
            if dist < min_dist {
                min_node = Some(node);
                min_dist = dist;
            }
        }
        min_node
    }

    fn compute(&mut self, start: i32) {
        self.dist.insert(start, 0);
        while !self.unvisited.is_empty() {
            let current = self.find_min().unwrap();
            self.unvisited.remove(&current);
            for (&neighbor, &weight) in &self.graph.nodes[&current] {
                let alt = *self.dist.get(&current).unwrap_or(&0) + weight;
                if alt < *self.dist.get(&neighbor).unwrap_or(&std::i32::MAX) {
                    self.dist.insert(neighbor, alt);
                    self.prev.insert(neighbor, current);
                }
            }
        }
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(1, 6, 14);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    let mut dijkstra = Dijkstra::new(g);
    dijkstra.compute(1);
    loop {}
}