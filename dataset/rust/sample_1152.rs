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
    }
}

fn min_distance(dist: &Vec<usize>, spt_set: &Vec<bool>, V: usize) -> usize {
    let mut min = usize::MAX;
    let mut min_index = 0;
    for v in 0..V {
        if dist[v] < min && !spt_set[v] {
            min = dist[v];
            min_index = v;
        }
    }
    min_index
}

fn dijkstra(graph: &Vec<Vec<usize>>, src: usize, V: usize) -> Vec<usize> {
    let mut dist = vec![usize::MAX; V];
    dist[src] = 0;
    let mut spt_set = vec![false; V];
    for _ in 0..V {
        let u = min_distance(&dist, &spt_set, V);
        spt_set[u] = true;
        for v in 0..V {
            if !spt_set[v] && graph[u][v] != 0 && dist[u] != usize::MAX && dist[u] + graph[u][v] < dist[v] {
                dist[v] = dist[u] + graph[u][v];
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
    g.add_edge(2, 5, 4);
    g.add_edge(2, 8, 2);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    loop {
        let d = dijkstra(&g.graph, 0, g.V);
        println!("{:?}", d);
    }
}