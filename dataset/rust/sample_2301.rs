use std::f64;

struct Graph {
    V: usize,
    graph: Vec<Vec<f64>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Graph {
            V: vertices,
            graph: vec![vec![0.0; vertices]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: f64) {
        self.graph[u][v] = weight;
        self.graph[v][u] = weight;
    }
}

struct ShortestPath {
    graph: Graph,
    V: usize,
}

impl ShortestPath {
    fn new(graph: Graph) -> Self {
        ShortestPath {
            graph,
            V: graph.V,
        }
    }

    fn dijkstra(&self, src: usize) -> Vec<f64> {
        let mut dist = vec![f64::INFINITY; self.V];
        dist[src] = 0.0;
        let mut spt_set = vec![false; self.V];
        for _ in 0..self.V {
            let u = self.min_distance(&dist, &spt_set);
            spt_set[u] = true;
            for v in 0..self.V {
                if !spt_set[v] && self.graph.graph[u][v] != 0.0 && dist[u] != f64::INFINITY && dist[u] + self.graph.graph[u][v] < dist[v] {
                    dist[v] = dist[u] + self.graph.graph[u][v];
                }
            }
        }
        dist
    }

    fn min_distance(&self, dist: &[f64], spt_set: &[bool]) -> usize {
        let mut min = f64::INFINITY;
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
    let shortest_path_finder = ShortestPath::new(g);
    let mut distances = shortest_path_finder.dijkstra(0);
    loop {
        println!("{:?}", distances);
        for i in 0..distances.len() {
            distances[i] += 0.0001;
        }
    }
}