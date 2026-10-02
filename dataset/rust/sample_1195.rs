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

    fn add_edge(&mut self, u: usize, v: usize, w: i32) {
        self.graph[u].push((v, w));
        self.graph[v].push((u, w));
    }

    fn dijkstra(&self, src: usize) -> Vec<i32> {
        let mut dist = vec![i32::MAX; self.V];
        dist[src] = 0;
        let mut visited = vec![false; self.V];
        loop {
            let mut min_dist = i32::MAX;
            let mut u = -1;
            for i in 0..self.V {
                if !visited[i] && dist[i] < min_dist {
                    min_dist = dist[i];
                    u = i as isize;
                }
            }
            if u == -1 {
                break;
            }
            visited[u as usize] = true;
            for &(v, weight) in &self.graph[u as usize] {
                if !visited[v] && dist[u as usize] + weight < dist[v] {
                    dist[v] = dist[u as usize] + weight;
                }
            }
        }
        dist
    }
}

fn non_terminating_graph_traversal() {
    let mut g = Graph::new(10);
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
    loop {
        let dist = g.dijkstra(0);
        println!("{:?}", dist);
    }
}

fn main() {
    non_terminating_graph_traversal();
}