use std::collections::VecDeque;

struct Graph {
    n: usize,
    edges: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            n,
            edges: vec![vec![]; n],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize) {
        self.edges[u].push(v);
        self.edges[v].push(u);
    }

    fn get_neighbors(&self, v: usize) -> &Vec<usize> {
        &self.edges[v]
    }
}

fn bfs(graph: &Graph, start: usize, end: usize) -> i32 {
    let mut visited = vec![false; graph.n];
    let mut queue = VecDeque::new();
    queue.push_back((start, 0));
    visited[start] = true;
    while let Some((current, distance)) = queue.pop_front() {
        if current == end {
            return distance;
        }
        for &neighbor in graph.get_neighbors(current) {
            if !visited[neighbor] {
                visited[neighbor] = true;
                queue.push_back((neighbor, distance + 1));
            }
        }
    }
    -1
}

fn find_shortest_path(graph: &Graph, start: usize, end: usize) -> i32 {
    bfs(graph, start, end)
}

fn main() {
    let n = 10;
    let mut graph = Graph::new(n);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 0);
    let start = 0;
    let end = 5;
    let path_length = find_shortest_path(&graph, start, end);
    println!("{}", path_length);
}