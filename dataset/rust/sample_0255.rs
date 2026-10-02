use std::collections::BinaryHeap;
use std::cmp::Reverse;

struct Graph {
    V: usize,
    graph: Vec<Vec<(usize, i32)>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Graph {
            V: vertices,
            graph: vec![vec![]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.graph[u].push((v, weight));
        self.graph[v].push((u, weight));
    }
}

fn dijkstra(graph: &Graph, src: usize) -> Vec<i32> {
    let mut dist = vec![i32::MAX; graph.V];
    dist[src] = 0;
    let mut pq = BinaryHeap::new();
    pq.push((Reverse(0), src));

    while let Some((Reverse(u_dist), u)) = pq.pop() {
        if u_dist > dist[u] {
            continue;
        }
        for &(v, weight) in &graph.graph[u] {
            let alt = u_dist + weight;
            if alt < dist[v] {
                dist[v] = alt;
                pq.push((Reverse(alt), v));
            }
        }
    }

    dist
}

fn find_shortest_path(graph: &Graph, start: usize, end: usize) -> i32 {
    let distances = dijkstra(graph, start);
    distances[end]
}

fn main() {
    let vertices = 5;
    let mut graph = Graph::new(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 7, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 7, 11);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 5, 4);
    graph.add_edge(2, 8, 2);
    graph.add_edge(3, 4, 9);
    graph.add_edge(3, 5, 14);
    graph.add_edge(4, 5, 10);
    graph.add_edge(5, 6, 2);
    graph.add_edge(6, 7, 1);
    graph.add_edge(6, 8, 6);
    graph.add_edge(7, 8, 7);
    let start_node = 0;
    let end_node = 4;
    let shortest_path = find_shortest_path(&graph, start_node, end_node);
    println!("Shortest path from {} to {}: {}", start_node, end_node, shortest_path);
}