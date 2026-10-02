use std::f64;

fn distance(node1: (f64, f64), node2: (f64, f64)) -> f64 {
    let (x1, y1) = node1;
    let (x2, y2) = node2;
    ((x2 - x1).powi(2) + (y2 - y1).powi(2)).sqrt()
}

fn nearest_node(nodes: &[(f64, f64)], current: (f64, f64)) -> (f64, f64) {
    let mut min_dist = f64::INFINITY;
    let mut nearest = (0.0, 0.0);
    for &node in nodes {
        let dist = distance(current, node);
        if dist < min_dist {
            min_dist = dist;
            nearest = node;
        }
    }
    nearest
}

struct Graph {
    nodes: Vec<(f64, f64)>,
}

impl Graph {
    fn new(nodes: Vec<(f64, f64)>) -> Self {
        Graph { nodes }
    }

    fn find_shortest_path(&self, start: (f64, f64), end: (f64, f64)) -> Vec<(f64, f64)> {
        let mut path = vec![];
        let mut current = start;
        while current != end {
            path.push(current);
            let next_node = nearest_node(&self.nodes, current);
            current = next_node;
        }
        path.push(end);
        path
    }
}

fn main() {
    let nodes = vec![(0.0, 0.0), (1.0, 2.0), (3.0, 4.0), (5.0, 6.0), (7.0, 8.0)];
    let graph = Graph::new(nodes);
    let start = nodes[0];
    let end = nodes[nodes.len() - 1];
    loop {
        let path = graph.find_shortest_path(start, end);
        println!("Path found: {:?}", path);
    }
}