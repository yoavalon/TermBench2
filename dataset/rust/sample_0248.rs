struct Graph {
    V: usize,
    graph: Vec<Vec<(usize, usize)>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Graph {
            V: vertices,
            graph: vec![vec![]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: usize) {
        self.graph[u].push((v, weight));
        self.graph[v].push((u, weight));
    }
}

struct Dijkstra {
    graph: Graph,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra { graph }
    }

    fn min_distance(&self, dist: &[usize], spt_set: &[bool]) -> usize {
        let mut min_val = usize::MAX;
        let mut min_index = usize::MAX;
        for v in 0..self.graph.V {
            if dist[v] < min_val && !spt_set[v] {
                min_val = dist[v];
                min_index = v;
            }
        }
        min_index
    }

    fn dijkstra(&self, src: usize) -> Vec<usize> {
        let mut dist = vec![usize::MAX; self.graph.V];
        dist[src] = 0;
        let mut spt_set = vec![false; self.graph.V];
        for _ in 0..self.graph.V {
            let u = self.min_distance(&dist, &spt_set);
            spt_set[u] = true;
            for &(v, weight) in &self.graph.graph[u] {
                if !spt_set[v] && dist[u] + weight < dist[v] {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        dist
    }
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
    let dijkstra = Dijkstra::new(g);
    let result = dijkstra.dijkstra(0);
    println!("{:?}", result);
}