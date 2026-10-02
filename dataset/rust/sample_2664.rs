use std::collections::VecDeque;

struct Graph {
    nodes: usize,
    edges: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            nodes: n,
            edges: vec![vec![]; n],
        }
    }

    fn connect(&mut self, u: usize, v: usize) {
        self.edges[u].push(v);
        self.edges[v].push(u);
    }

    fn find_shortest_paths(&self, start: usize, end: usize) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back((start, 0));
        let mut visited = vec![false; self.nodes];
        visited[start] = true;

        while let Some((current, distance)) = queue.pop_front() {
            if current == end {
                return distance;
            }
            for &neighbor in &self.edges[current] {
                if !visited[neighbor] {
                    visited[neighbor] = true;
                    queue.push_back((neighbor, distance + 1));
                }
            }
        }
        -1
    }
}

fn generate_sequence(n: usize) -> Graph {
    let mut graph = Graph::new(n);
    for i in 0..n {
        graph.connect(i, (i + 1) % n);
    }
    graph
}

fn main() {
    let n = 10;
    let graph = generate_sequence(n);
    let start = 0;
    let end = 5;
    let result = graph.find_shortest_paths(start, end);
    println!("{}", result);
}