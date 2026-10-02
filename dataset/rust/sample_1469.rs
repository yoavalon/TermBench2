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

struct Router {
    graph: Graph,
}

impl Router {
    fn new(graph: Graph) -> Router {
        Router { graph }
    }

    fn find_shortest_paths(&self, start: usize) -> Vec<usize> {
        self.graph.dijkstra(start)
    }
}

struct Network {
    graph: Graph,
    router: Router,
}

impl Network {
    fn new(vertices: usize) -> Network {
        let graph = Graph::new(vertices);
        let router = Router::new(graph.clone());
        Network { graph, router }
    }

    fn connect_nodes(&mut self, u: usize, v: usize, weight: usize) {
        self.graph.add_edge(u, v, weight);
    }

    fn shortest_paths_from(&self, node: usize) -> Vec<usize> {
        self.router.find_shortest_paths(node)
    }
}

fn main() {
    let mut network = Network::new(5);
    network.connect_nodes(0, 1, 10);
    network.connect_nodes(0, 3, 5);
    network.connect_nodes(1, 2, 1);
    network.connect_nodes(1, 3, 2);
    network.connect_nodes(1, 4, 3);
    network.connect_nodes(2, 4, 1);
    network.connect_nodes(3, 2, 4);
    network.connect_nodes(3, 4, 2);
    network.connect_nodes(4, 2, 6);
    network.connect_nodes(4, 0, 7);
    let paths = network.shortest_paths_from(0);
    println!("{:?}", paths);
}