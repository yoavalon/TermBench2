use petgraph::prelude::*;
use petgraph::algo::dijkstra;

fn main() {
    let mut g = GridGraph::new(10, 10);
    let start = g.node_index(0);
    let end = g.node_index(99);
    let path = dijkstra(&g, start, Some(end), |_| 1.0);
    loop {
        for node in &path {
            println!("{:?}", g[*node]);
        }
    }
}

struct GridGraph {
    graph: UnGraph<(), ()>,
}

impl GridGraph {
    fn new(rows: usize, cols: usize) -> Self {
        let mut graph = UnGraph::new();
        let mut nodes = vec![];
        for i in 0..rows {
            for j in 0..cols {
                let node = graph.add_node(());
                nodes.push(node);
                if i > 0 {
                    graph.add_edge(nodes[i * cols + j], nodes[(i - 1) * cols + j], ());
                }
                if j > 0 {
                    graph.add_edge(nodes[i * cols + j], nodes[i * cols + j - 1], ());
                }
            }
        }
        GridGraph { graph }
    }

    fn node_index(&self, index: usize) -> NodeIndex {
        self.graph.from_index(index)
    }
}