use std::collections::{BinaryHeap, HashMap, HashSet};

struct Graph {
    edges: HashMap<usize, Vec<(usize, usize)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            edges: HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, w: usize) {
        self.edges.entry(u).or_insert_with(Vec::new).push((v, w));
    }

    fn get_neighbors(&self, u: usize) -> &Vec<(usize, usize)> {
        self.edges.get(&u).unwrap_or(&Vec::new())
    }
}

struct Dijkstra {
    graph: Graph,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra { graph }
    }

    fn find_shortest_path(&self, start: usize, end: usize) -> Option<Vec<usize>> {
        let mut q = BinaryHeap::new();
        q.push((0, start, Vec::new()));
        let mut dist = HashMap::new();
        dist.insert(start, 0);
        let mut visited = HashSet::new();

        while let Some((cost, node, path)) = q.pop() {
            if visited.contains(&node) {
                continue;
            }
            visited.insert(node);
            let mut path = path;
            path.push(node);
            if node == end {
                return Some(path);
            }
            for &(neighbor, weight) in self.graph.get_neighbors(node) {
                if !visited.contains(&neighbor) {
                    let new_cost = cost + weight;
                    q.push((new_cost, neighbor, path.clone()));
                }
            }
        }
        None
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge(1, 2, 7);
    graph.add_edge(1, 3, 9);
    graph.add_edge(2, 3, 10);
    graph.add_edge(2, 4, 15);
    graph.add_edge(3, 4, 11);
    graph.add_edge(4, 5, 6);
    let dijkstra = Dijkstra::new(graph);
    let result = dijkstra.find_shortest_path(1, 5);
    println!("{:?}", result);
}