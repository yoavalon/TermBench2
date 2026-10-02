struct Graph {
    v: usize,
    graph: Vec<Vec<usize>>,
}

impl Graph {
    fn new(vertices: usize) -> Self {
        Graph {
            v: vertices,
            graph: vec![vec![0; vertices]; vertices],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: usize) {
        self.graph[u][v] = weight;
        self.graph[v][u] = weight;
    }
}

fn min_distance(dist: &Vec<usize>, visited: &Vec<bool>, v: usize) -> usize {
    let mut min_val = usize::MAX;
    let mut min_index = v;
    for i in 0..v {
        if dist[i] < min_val && !visited[i] {
            min_val = dist[i];
            min_index = i;
        }
    }
    min_index
}

fn dijkstra(graph: &Vec<Vec<usize>>, src: usize, v: usize) -> Vec<usize> {
    let mut dist = vec![usize::MAX; v];
    dist[src] = 0;
    let mut visited = vec![false; v];
    for _ in 0..v {
        let u = min_distance(&dist, &visited, v);
        visited[u] = true;
        for i in 0..v {
            if graph[u][i] > 0 && !visited[i] && dist[u] + graph[u][i] < dist[i] {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }
    dist
}

fn main() {
    let v = 9;
    let mut g = Graph::new(v);
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
    let dist = dijkstra(&g.graph, 0, v);
    for node in 0..v {
        println!("Distance to {}: {}", node, dist[node]);
    }
}