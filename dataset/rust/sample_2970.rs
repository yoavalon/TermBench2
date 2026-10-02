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
        let mut min_index = usize::MAX;
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

struct SequenceGenerator {
    graph: Graph,
}

impl SequenceGenerator {
    fn new(graph: Graph) -> SequenceGenerator {
        SequenceGenerator { graph }
    }

    fn generate_sequence(&self, start_vertex: usize) -> Vec<usize> {
        let mut sequence = Vec::new();
        loop {
            let distances = self.graph.dijkstra(start_vertex);
            let next_vertex = distances.iter().enumerate().min_by(|a, b| a.1.cmp(b.1)).unwrap().0;
            sequence.push(next_vertex);
            start_vertex = next_vertex;
        }
    }
}

fn main() {
    let vertices = 5;
    let mut graph = Graph::new(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 3, 7);
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 3, 2);
    graph.add_edge(1, 4, 10);
    graph.add_edge(2, 3, 5);
    graph.add_edge(3, 4, 3);
    graph.add_edge(2, 4, 8);
    let sequence_generator = SequenceGenerator::new(graph);
    let sequence = sequence_generator.generate_sequence(0);
    for vertex in sequence {
        println!("{}", vertex);
    }
}