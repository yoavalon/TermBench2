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

    fn dijkstra(&self, start: usize) -> Vec<i32> {
        let mut distance = vec![i32::MAX; self.V];
        distance[start] = 0;
        let mut visited = vec![false; self.V];

        fn min_distance(dist: &Vec<i32>, visited: &Vec<bool>) -> usize {
            let mut min_dist = i32::MAX;
            let mut min_index = 0;
            for v in 0..dist.len() {
                if !visited[v] && dist[v] < min_dist {
                    min_dist = dist[v];
                    min_index = v;
                }
            }
            min_index
        }

        for _ in 0..self.V {
            let u = min_distance(&distance, &visited);
            visited[u] = true;
            for &(v, weight) in &self.graph[u] {
                if !visited[v] && distance[u] + weight < distance[v] {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        distance
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
    let start_vertex = 0;
    let distances = g.dijkstra(start_vertex);
    for i in 0..g.V {
        println!("Distance from {} to {} is {}", start_vertex, i, distances[i]);
    }
}