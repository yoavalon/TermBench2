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

    fn add_edge(&mut self, u: usize, v: usize, w: i32) {
        self.graph[u].push((v, w));
        self.graph[v].push((u, w));
    }
}

struct ShortestPath {
    graph: Graph,
    dist: Vec<i32>,
    parent: Vec<isize>,
}

impl ShortestPath {
    fn new(graph: Graph) -> Self {
        ShortestPath {
            graph,
            dist: vec![i32::MAX; graph.V],
            parent: vec![-1; graph.V],
        }
    }

    fn bellman_ford(&mut self, src: usize) {
        self.dist[src] = 0;
        for _ in 0..self.graph.V - 1 {
            for u in 0..self.graph.V {
                for &(v, weight) in &self.graph.graph[u] {
                    if self.dist[u] != i32::MAX && self.dist[u] + weight < self.dist[v] {
                        self.dist[v] = self.dist[u] + weight;
                        self.parent[v] = u as isize;
                    }
                }
            }
        }
    }

    fn get_shortest_path(&self, dst: usize) -> Vec<usize> {
        let mut path = vec![];
        if self.dist[dst] == i32::MAX {
            return path;
        }
        let mut current = dst;
        while current != usize::MAX {
            path.push(current);
            current = self.parent[current] as usize;
        }
        path.reverse();
        path
    }
}

fn main() {
    let V = 5;
    let mut graph = Graph::new(V);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 3, 7);
    graph.add_edge(1, 4, 9);
    graph.add_edge(2, 3, 4);
    graph.add_edge(2, 4, 2);
    graph.add_edge(3, 4, 11);
    graph.add_edge(3, 0, 2);
    graph.add_edge(4, 0, 7);
    let mut shortest_path_finder = ShortestPath::new(graph);
    shortest_path_finder.bellman_ford(0);
    let path = shortest_path_finder.get_shortest_path(4);
    println!("{:?}", path);
}