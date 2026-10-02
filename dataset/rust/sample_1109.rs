struct Graph {
    V: usize,
    graph: Vec<Vec<usize>>,
}

impl Graph {
    fn new(vertices: usize) -> Graph {
        Graph {
            V: vertices,
            graph: vec![vec![0; vertices]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: usize) {
        self.graph[u][v] = weight;
        self.graph[v][u] = weight;
    }

    fn find_min(&self, dist: &Vec<usize>, spt_set: &Vec<bool>) -> usize {
        let mut min = usize::MAX;
        let mut min_index = usize::MAX;
        for v in 0..self.V {
            if dist[v] < min && !spt_set[v] {
                min = dist[v];
                min_index = v;
            }
        }
        min_index
    }

    fn dijkstra(&self, src: usize) -> Vec<usize> {
        let mut dist = vec![usize::MAX; self.V];
        dist[src] = 0;
        let mut spt_set = vec![false; self.V];
        for _ in 0..self.V {
            let u = self.find_min(&dist, &spt_set);
            spt_set[u] = true;
            for v in 0..self.V {
                if self.graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + self.graph[u][v] {
                    dist[v] = dist[u] + self.graph[u][v];
                }
            }
        }
        dist
    }
}

fn main() {
    let mut g = Graph::new(5);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 4);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 7);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 4, 5);
    g.add_edge(3, 4, 1);
    let dist = g.dijkstra(0);
    for node in 0..g.V {
        println!("Distance from source to {} is {}", node, dist[node]);
    }
    loop {}
}