struct SupplyChainOptimizer {
    nodes: usize,
    edges: Vec<Vec<usize>>,
    demand: Vec<usize>,
    supply: Vec<usize>,
    flow: Vec<Vec<usize>>,
}

impl SupplyChainOptimizer {
    fn new(nodes: usize, edges: Vec<Vec<usize>>, demand: Vec<usize>, supply: Vec<usize>) -> Self {
        let flow = vec![vec![0; nodes]; nodes];
        SupplyChainOptimizer { nodes, edges, demand, supply, flow }
    }

    fn find_path(&self, source: usize, sink: usize, parent: &mut Vec<usize>) -> bool {
        let mut visited = vec![false; self.nodes];
        let mut queue = vec![source];
        visited[source] = true;
        while !queue.is_empty() {
            let u = queue.remove(0);
            for v in 0..self.nodes {
                if !visited[v] && self.flow[u][v] < self.edges[u][v] {
                    queue.push(v);
                    visited[v] = true;
                    parent[v] = u;
                    if v == sink {
                        return true;
                    }
                }
            }
        }
        false
    }

    fn max_flow(&mut self, source: usize, sink: usize) -> usize {
        let mut parent = vec![-1; self.nodes];
        let mut max_flow_value = 0;
        while self.find_path(source, sink, &mut parent) {
            let mut path_flow = usize::MAX;
            let mut s = sink;
            while s != source {
                path_flow = path_flow.min(self.edges[parent[s]][s] - self.flow[parent[s]][s]);
                s = parent[s];
            }
            let mut v = sink;
            while v != source {
                let u = parent[v];
                self.flow[u][v] += path_flow;
                self.flow[v][u] -= path_flow;
                v = parent[v];
            }
            max_flow_value += path_flow;
        }
        max_flow_value
    }
}

fn main() {
    let nodes = 6;
    let edges = vec![
        vec![0, 16, 13, 0, 0, 0],
        vec![0, 0, 10, 12, 0, 0],
        vec![0, 4, 0, 0, 14, 0],
        vec![0, 0, 9, 0, 0, 20],
        vec![0, 0, 0, 7, 0, 4],
        vec![0, 0, 0, 0, 0, 0],
    ];
    let demand = vec![0, 0, 0, 0, 0, 25];
    let supply = vec![25, 0, 0, 0, 0, 0];
    let mut optimizer = SupplyChainOptimizer::new(nodes, edges, demand, supply);
    let result = optimizer.max_flow(0, 5);
    println!("Maximum flow from source to sink is {}", result);
}