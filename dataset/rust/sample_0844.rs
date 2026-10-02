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

fn min_distance(dist: &Vec<i32>, spt_set: &Vec<bool>, V: usize) -> usize {
    let mut min = i32::MAX;
    let mut min_index = usize::MAX;
    for v in 0..V {
        if dist[v] < min && !spt_set[v] {
            min = dist[v];
            min_index = v;
        }
    }
    min_index
}

fn dijkstra(graph: &Graph, src: usize) -> Vec<i32> {
    let V = graph.V;
    let mut dist = vec![i32::MAX; V];
    dist[src] = 0;
    let mut spt_set = vec![false; V];
    for _ in 0..V {
        let u = min_distance(&dist, &spt_set, V);
        spt_set[u] = true;
        for &(v, weight) in &graph.graph[u] {
            if !spt_set[v] && dist[u] != i32::MAX && (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    dist
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
    println!("Vertex \tDistance from Source");
    for node in 0..g.V {
        println!("{} \t{}", node, dist[node]);
    }
}