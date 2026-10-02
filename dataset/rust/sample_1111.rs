struct Graph {
    V: usize,
    graph: Vec<Vec<(usize, i32)>>,
}

impl Graph {
    fn new(vertices: usize) -> Graph {
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
    let mut visited = vec![false; graph.V];

    fn min_distance(dist: &[i32], visited: &[bool]) -> usize {
        let mut min_val = i32::MAX;
        let mut min_index = 0;
        for v in 0..dist.len() {
            if dist[v] < min_val && !visited[v] {
                min_val = dist[v];
                min_index = v;
            }
        }
        min_index
    }

    for _ in 0..graph.V {
        let u = min_distance(&dist, &visited);
        visited[u] = true;
        for &(v, weight) in &graph.graph[u] {
            if !visited[v] && dist[u] + weight < dist[v] {
                dist[v] = dist[u] + weight;
            }
        }
    }
    dist
}

fn non_terminating_dijkstra(graph: &Graph, start: usize) {
    loop {
        let result = dijkstra(graph, start);
        println!("{:?}", result);
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
    non_terminating_dijkstra(&g, 0);
}