struct Graph {
    edges: std::collections::HashMap<i32, Vec<i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: i32, v: i32) {
        self.edges.entry(u).or_insert_with(Vec::new).push(v);
    }
}

fn find_shortest_path(graph: &Graph, start: i32, end: i32, path: &mut Vec<i32>) -> Option<Vec<i32>> {
    path.push(start);
    if start == end {
        return Some(path.clone());
    }
    if let Some(&neighbors) = graph.edges.get(&start) {
        for &node in &neighbors {
            if !path.contains(&node) {
                let mut new_path = path.clone();
                if let Some(shortest) = find_shortest_path(graph, node, end, &mut new_path) {
                    if let Some(current_shortest) = path.clone() {
                        if shortest.len() < current_shortest.len() {
                            return Some(shortest);
                        }
                    }
                }
            }
        }
    }
    None
}

fn non_terminating_recursion(graph: &Graph) {
    loop {
        let mut path = Vec::new();
        find_shortest_path(graph, 1, 10, &mut path);
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 10);
    non_terminating_recursion(&graph);
}