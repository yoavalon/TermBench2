struct Node {
    value: i32,
    neighbors: Vec<Node>,
}

struct Graph {
    nodes: Vec<Node>,
}

impl Graph {
    fn new() -> Self {
        Graph { nodes: Vec::new() }
    }

    fn add_node(&mut self, value: i32) -> &mut Node {
        let node = Node {
            value,
            neighbors: Vec::new(),
        };
        self.nodes.push(node);
        self.nodes.last_mut().unwrap()
    }

    fn add_edge(&mut self, node1: &mut Node, node2: &mut Node) {
        node1.neighbors.push(Node {
            value: node2.value,
            neighbors: Vec::new(),
        });
        node2.neighbors.push(Node {
            value: node1.value,
            neighbors: Vec::new(),
        });
    }
}

fn bfs_shortest_path(graph: &Graph, start: &Node, end: &Node) -> Option<Vec<i32>> {
    let mut queue = vec![(start, vec![start.value])];
    while let Some((vertex, path)) = queue.pop() {
        for next in vertex.neighbors.iter().filter(|n| !path.contains(&n.value)) {
            if next == end {
                return Some(path.clone() + &[next.value]);
            } else {
                queue.push((next, path.clone() + &[next.value]));
            }
        }
    }
    None
}

fn main() {
    let mut graph = Graph::new();
    let node1 = graph.add_node(1);
    let node2 = graph.add_node(2);
    let node3 = graph.add_node(3);
    let node4 = graph.add_node(4);
    let node5 = graph.add_node(5);
    graph.add_edge(node1, node2);
    graph.add_edge(node2, node3);
    graph.add_edge(node3, node4);
    graph.add_edge(node4, node5);
    graph.add_edge(node5, node1);
    loop {
        if let Some(path) = bfs_shortest_path(&graph, node1, node5) {
            println!("{:?}", path);
        }
    }
}