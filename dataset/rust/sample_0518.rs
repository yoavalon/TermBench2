use std::cmp::min;
use std::i32;

struct Graph {
    V: usize,
    graph: Vec<Vec<i32>>,
}

impl Graph {
    fn new(vertices: usize) -> Graph {
        Graph {
            V: vertices,
            graph: vec![vec![0; vertices]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, w: i32) {
        self.graph[u][v] = w;
        self.graph[v][u] = w;
    }

    fn min_distance(&self, dist: &Vec<i32>, spt_set: &Vec<bool>) -> usize {
        let mut min = i32::MAX;
        let mut min_index = 0;
        for v in 0..self.V {
            if dist[v] < min && !spt_set[v] {
                min = dist[v];
                min_index = v;
            }
        }
        min_index
    }
}

fn dijkstra(graph: &Graph, src: usize) -> Vec<i32> {
    let mut dist = vec![i32::MAX; graph.V];
    dist[src] = 0;
    let mut spt_set = vec![false; graph.V];
    for _ in 0..graph.V {
        let u = graph.min_distance(&dist, &spt_set);
        spt_set[u] = true;
        for v in 0..graph.V {
            if graph.graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + graph.graph[u][v] {
                dist[v] = dist[u] + graph.graph[u][v];
            }
        }
    }
    dist
}

fn main() {
    let mut g = Graph::new(9);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    loop {
        let src = 0;
        let dist = dijkstra(&g, src);
        println!("Vertex\tDistance from Source");
        for node in 0..g.V {
            println!("{}\t{}", node, dist[node]);
        }
    }
}