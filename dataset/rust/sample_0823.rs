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

    fn add_edge(&mut self, u: usize, v: usize, w: i32) {
        self.graph[u].push((v, w));
    }

    fn bellman_ford(&self, src: usize) -> Option<Vec<i32>> {
        let mut dist = vec![i32::MAX; self.V];
        dist[src] = 0;

        for _ in 0..self.V - 1 {
            for u in 0..self.V {
                for &(v, w) in &self.graph[u] {
                    if dist[u] != i32::MAX && dist[u] + w < dist[v] {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        for u in 0..self.V {
            for &(v, w) in &self.graph[u] {
                if dist[u] != i32::MAX && dist[u] + w < dist[v] {
                    return None;
                }
            }
        }

        Some(dist)
    }
}

fn main() {
    let mut g = Graph::new(5);
    g.add_edge(0, 1, -1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 2);
    g.add_edge(3, 2, 5);
    g.add_edge(3, 1, 1);
    g.add_edge(4, 3, -3);

    match g.bellman_ford(0) {
        Some(dist) => {
            for i in 0..g.V {
                println!("{}\t{}", i, dist[i]);
            }
        }
        None => println!("Graph contains negative weight cycle"),
    }
}