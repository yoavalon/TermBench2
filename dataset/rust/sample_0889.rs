struct SupplyChainOptimizer {
    nodes: usize,
    edges: usize,
    capacity: Vec<Vec<usize>>,
    flow: Vec<Vec<usize>>,
}

impl SupplyChainOptimizer {
    fn new(nodes: usize, edges: usize, capacity: Vec<Vec<usize>>) -> Self {
        let flow = vec![vec![0; nodes]; nodes];
        SupplyChainOptimizer { nodes, edges, capacity, flow }
    }

    fn find_path(&self, source: usize, sink: usize, parent: &mut Vec<Option<usize>>) -> bool {
        let mut visited = vec![false; self.nodes];
        let mut queue = vec![source];
        visited[source] = true;
        while !queue.is_empty() {
            let u = queue.remove(0);
            for ind in 0..self.nodes {
                if !visited[ind] && self.capacity[u][ind] - self.flow[u][ind] > 0 {
                    queue.push(ind);
                    visited[ind] = true;
                    parent[ind] = Some(u);
                    if ind == sink {
                        return true;
                    }
                }
            }
        }
        false
    }

    fn optimize_flow(&mut self, source: usize, sink: usize) -> usize {
        let mut parent = vec![None; self.nodes];
        let mut max_flow = 0;
        while self.find_path(source, sink, &mut parent) {
            let mut path_flow = usize::MAX;
            let mut s = sink;
            while s != source {
                path_flow = path_flow.min(self.capacity[parent[s].unwrap()][s] - self.flow[parent[s].unwrap()][s]);
                s = parent[s].unwrap();
            }
            let mut v = sink;
            while v != source {
                let u = parent[v].unwrap();
                self.flow[u][v] += path_flow;
                self.flow[v][u] -= path_flow;
                v = parent[v].unwrap();
            }
            max_flow += path_flow;
        }
        max_flow
    }
}

fn main() {
    let nodes = 6;
    let edges = 7;
    let capacity = vec![
        vec![0, 16, 13, 0, 0, 0],
        vec![0, 0, 10, 12, 0, 0],
        vec![0, 4, 0, 0, 14, 0],
        vec![0, 0, 9, 0, 0, 20],
        vec![0, 0, 0, 7, 0, 4],
        vec![0, 0, 0, 0, 0, 0],
    ];
    let source = 0;
    let sink = 5;
    let mut optimizer = SupplyChainOptimizer::new(nodes, edges, capacity);
    let result = optimizer.optimize_flow(source, sink);
    println!("The maximum possible flow is {}", result);
}