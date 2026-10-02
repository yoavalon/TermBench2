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

struct ShortestPath {
    graph: Graph,
}

impl ShortestPath {
    fn new(graph: Graph) -> Self {
        ShortestPath { graph }
    }

    fn min_distance(&self, dist: &Vec<i32>, sptSet: &Vec<bool>) -> usize {
        let mut min = i32::MAX;
        let mut min_index = 0;
        for v in 0..self.graph.V {
            if dist[v] < min && !sptSet[v] {
                min = dist[v];
                min_index = v;
            }
        }
        min_index
    }

    fn dijkstra(&self, src: usize) -> Vec<i32> {
        let mut dist = vec![i32::MAX; self.graph.V];
        dist[src] = 0;
        let mut sptSet = vec![false; self.graph.V];
        for _ in 0..self.graph.V {
            let u = self.min_distance(&dist, &sptSet);
            sptSet[u] = true;
            for &(v, weight) in &self.graph.graph[u] {
                if !sptSet[v] && dist[u] != i32::MAX && (dist[u] + weight < dist[v]) {
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
    let sp = ShortestPath::new(g);
    println!("{:?}", sp.dijkstra(0));
}