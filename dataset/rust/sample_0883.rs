struct Graph {
    V: usize,
    graph: Vec<Vec<usize>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Graph {
            V: vertices,
            graph: vec![vec![0; vertices]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: usize) {
        self.graph[u][v] = weight;
        self.graph[v][u] = weight;
    }
}

fn dijkstra(graph: &Graph, src: usize, dist: &mut [usize], visited: &mut [bool], path: &mut [isize]) {
    if visited.iter().all(|&v| v) {
        return;
    }
    let u = (0..graph.V)
        .filter(|&v| !visited[v])
        .min_by_key(|&x| dist[x])
        .unwrap();
    visited[u] = true;
    for v in 0..graph.V {
        if !visited[v] && graph.graph[u][v] != 0 {
            if dist[u] + graph.graph[u][v] < dist[v] {
                dist[v] = dist[u] + graph.graph[u][v];
                path[v] = u as isize;
            }
        }
    }
    dijkstra(graph, src, dist, visited, path);
}

fn find_shortest_path(graph: &Graph, src: usize, dest: usize) -> Vec<usize> {
    let mut dist = vec![usize::MAX; graph.V];
    dist[src] = 0;
    let mut visited = vec![false; graph.V];
    let mut path = vec![-1; graph.V];
    dijkstra(graph, src, &mut dist, &mut visited, &mut path);
    if dist[dest] == usize::MAX {
        return vec![];
    }
    let mut result = vec![];
    let mut current = dest;
    while current != -1 {
        result.insert(0, current);
        current = path[current] as usize;
    }
    result
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
    println!("{:?}", find_shortest_path(&g, 0, 4));
}