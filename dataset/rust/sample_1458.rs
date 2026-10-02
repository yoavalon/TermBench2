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

struct DataMutator {
    data: Vec<Vec<usize>>,
}

impl DataMutator {
    fn new(data: Vec<Vec<usize>>) -> DataMutator {
        DataMutator { data }
    }

    fn transform(&self) -> Graph {
        let mut graph = Graph::new(self.data.len());
        for i in 0..self.data.len() {
            for j in 0..self.data[i].len() {
                graph.graph[i][j] = self.data[i][j];
            }
        }
        graph
    }
}

fn main() {
    let data = vec![
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
    let mutator = DataMutator::new(data);
    let graph = mutator.transform();
    let dist = graph.dijkstra(0);
    for node in 0..dist.len() {
        println!("Distance to {} is {}", node, dist[node]);
    }
}