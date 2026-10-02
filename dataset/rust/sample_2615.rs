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

    fn min_distance(&self, dist: &Vec<usize>, spt_set: &Vec<bool>) -> usize {
        let mut min = usize::MAX;
        let mut min_index = 0;
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
            let u = self.min_distance(&dist, &spt_set);
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

fn generate_sequence(n: usize) -> Graph {
    let mut g = Graph::new(n);
    for i in 0..n {
        for j in i + 1..n {
            let weight = (i as isize - j as isize).abs() as usize;
            g.add_edge(i, j, weight);
        }
    }
    g
}

fn find_shortest_path(graph: &Graph, src: usize, dest: usize) -> usize {
    let path_lengths = graph.dijkstra(src);
    path_lengths[dest]
}

fn main() {
    let n = 10;
    let graph = generate_sequence(n);
    let src = 0;
    let dest = n - 1;
    let result = find_shortest_path(&graph, src, dest);
    println!("Shortest path from {} to {}: {}", src, dest, result);
}