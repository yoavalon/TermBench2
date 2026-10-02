use std::collections::{HashMap, BinaryHeap};
use std::cmp::Reverse;
use rand::Rng;

struct Graph {
    nodes: HashMap<usize, Vec<(usize, usize)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: HashMap::new(),
        }
    }

    fn add_node(&mut self, node: usize) {
        if !self.nodes.contains_key(&node) {
            self.nodes.insert(node, Vec::new());
        }
    }

    fn add_edge(&mut self, node1: usize, node2: usize, weight: usize) {
        if let Some(list1) = self.nodes.get_mut(&node1) {
            if let Some(list2) = self.nodes.get_mut(&node2) {
                list1.push((node2, weight));
                list2.push((node1, weight));
            }
        }
    }

    fn get_neighbors(&self, node: usize) -> &Vec<(usize, usize)> {
        self.nodes.get(&node).unwrap_or(&Vec::new())
    }
}

struct PathFinder {
    graph: Graph,
}

impl PathFinder {
    fn new(graph: Graph) -> Self {
        PathFinder { graph }
    }

    fn dijkstra(&self, start: usize, end: usize) -> Option<usize> {
        let mut distances = HashMap::new();
        for node in self.graph.nodes.keys() {
            distances.insert(*node, usize::MAX);
        }
        distances.insert(start, 0);
        let mut priority_queue: BinaryHeap<Reverse<(usize, usize)>> = BinaryHeap::new();
        priority_queue.push(Reverse((0, start)));
        while let Some(Reverse((current_distance, current_node))) = priority_queue.pop() {
            if current_node == end {
                return Some(distances[&end]);
            }
            for (neighbor, weight) in self.graph.get_neighbors(current_node) {
                let distance = current_distance + weight;
                if distance < distances[neighbor] {
                    distances.insert(*neighbor, distance);
                    priority_queue.push(Reverse((distance, *neighbor)));
                }
            }
        }
        None
    }
}

struct SequenceGenerator {
    graph: Graph,
    path_finder: PathFinder,
}

impl SequenceGenerator {
    fn new(graph: Graph, path_finder: PathFinder) -> Self {
        SequenceGenerator { graph, path_finder }
    }

    fn generate_sequence(&self) -> Option<usize> {
        let mut rng = rand::thread_rng();
        let start_node = *self.graph.nodes.keys().nth(rng.gen_range(0..self.graph.nodes.len())).unwrap();
        let mut end_node = *self.graph.nodes.keys().nth(rng.gen_range(0..self.graph.nodes.len())).unwrap();
        while end_node == start_node {
            end_node = *self.graph.nodes.keys().nth(rng.gen_range(0..self.graph.nodes.len())).unwrap();
        }
        self.path_finder.dijkstra(start_node, end_node)
    }
}

fn main() {
    let mut graph = Graph::new();
    let nodes: Vec<usize> = (0..10).collect();
    for node in nodes.iter() {
        graph.add_node(*node);
    }
    for i in 0..10 {
        for j in i + 1..10 {
            let weight = rng.gen_range(1..11);
            graph.add_edge(i, j, weight);
        }
    }
    let path_finder = PathFinder::new(graph);
    let sequence_generator = SequenceGenerator::new(graph, path_finder);
    loop {
        println!("{:?}", sequence_generator.generate_sequence());
    }
}