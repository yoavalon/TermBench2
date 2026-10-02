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

struct Sequence {
    graph: Graph,
    start: usize,
}

impl Sequence {
    fn new(graph: Graph, start: usize) -> Self {
        Sequence { graph, start }
    }

    fn generate_sequence(&self) -> Vec<usize> {
        let dist = self.graph.dijkstra(self.start);
        let mut sequence = Vec::new();
        for i in 0..dist.len() {
            if i != self.start {
                sequence.push(dist[i]);
            }
        }
        sequence
    }
}

fn main() {
    let V = 9;
    let mut g = Graph::new(V);
    g.graph = vec![
        vec![0, 4, 0, 0, 0, 0, 0, 8, 0],
        vec![4, 0, 8, 0, 0, 0, 0, 11, 0],
        vec![0, 8, 0, 7, 0, 4, 0, 0, 2],
        vec![0, 0, 7, 0, 9, 14, 0, 0, 0],
        vec![0, 0, 0, 9, 0, 10, 0, 0, 0],
        vec![0, 0, 4, 14, 10, 0, 2, 0, 0],
        vec![0, 0, 0, 0, 0, 2, 0, 1, 6],
        vec![8, 11, 0, 0, 0, 0, 1, 0, 7],
        vec![0, 0, 2, 0, 0, 0, 6, 7, 0],
    ];
    let seq = Sequence::new(g, 0);
    println!("{:?}", seq.generate_sequence());
}