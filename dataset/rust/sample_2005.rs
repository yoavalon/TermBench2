struct Graph {
    V: usize,
    graph: Vec<Vec<isize>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Graph {
            V: vertices,
            graph: vec![vec![0; vertices]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: isize) {
        self.graph[u][v] = weight;
        self.graph[v][u] = weight;
    }
}

fn dijkstra(graph: &Graph, src: usize) -> Vec<isize> {
    let mut dist = vec![isize::MAX; graph.V];
    dist[src] = 0;
    let mut spt_set = vec![false; graph.V];
    for _ in 0..graph.V {
        let u = min_distance(&dist, &spt_set, graph.V);
        spt_set[u] = true;
        for v in 0..graph.V {
            if !spt_set[v] && graph.graph[u][v] != 0 && dist[u] != isize::MAX && dist[u] + graph.graph[u][v] < dist[v] {
                dist[v] = dist[u] + graph.graph[u][v];
            }
        }
    }
    dist
}

fn min_distance(dist: &[isize], spt_set: &[bool], V: usize) -> usize {
    let mut min = isize::MAX;
    let mut min_index = 0;
    for v in 0..V {
        if dist[v] < min && !spt_set[v] {
            min = dist[v];
            min_index = v;
        }
    }
    min_index
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
    let dist = dijkstra(&g, 0);
    for node in 0..g.V {
        println!("Distance from 0 to {} is {}", node, dist[node]);
    }
}