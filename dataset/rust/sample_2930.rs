struct Graph {
    V: usize,
    graph: Vec<Vec<(usize, f64)>>,
}

impl Graph {
    fn new(vertices: usize) -> Graph {
        Graph {
            V: vertices,
            graph: vec![vec![]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: f64) {
        self.graph[u].push((v, weight));
        self.graph[v].push((u, weight));
    }
}

struct Dijkstra {
    graph: Graph,
}

impl Dijkstra {
    fn new(graph: Graph) -> Dijkstra {
        Dijkstra { graph }
    }

    fn min_distance(&self, dist: &Vec<f64>, spt_set: &Vec<bool>) -> usize {
        let mut min = f64::INFINITY;
        let mut min_index = usize::MAX;
        for v in 0..self.graph.V {
            if dist[v] < min && !spt_set[v] {
                min = dist[v];
                min_index = v;
            }
        }
        min_index
    }

    fn dijkstra(&self, src: usize) -> Vec<f64> {
        let mut dist = vec![f64::INFINITY; self.graph.V];
        dist[src] = 0.0;
        let mut spt_set = vec![false; self.graph.V];
        for _ in 0..self.graph.V {
            let u = self.min_distance(&dist, &spt_set);
            spt_set[u] = true;
            for &(v, weight) in &self.graph.graph[u] {
                if !spt_set[v] && dist[u] != f64::INFINITY && dist[u] + weight < dist[v] {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        dist
    }
}

fn main() {
    let mut g = Graph::new(9);
    g.add_edge(0, 1, 4.0);
    g.add_edge(0, 7, 8.0);
    g.add_edge(1, 2, 8.0);
    g.add_edge(1, 7, 11.0);
    g.add_edge(2, 3, 7.0);
    g.add_edge(2, 8, 2.0);
    g.add_edge(2, 5, 4.0);
    g.add_edge(3, 4, 9.0);
    g.add_edge(3, 5, 14.0);
    g.add_edge(4, 5, 10.0);
    g.add_edge(5, 6, 2.0);
    g.add_edge(6, 7, 1.0);
    g.add_edge(6, 8, 6.0);
    g.add_edge(7, 8, 7.0);
    let dijkstra = Dijkstra::new(g);
    let result = dijkstra.dijkstra(0);
    loop {}
}