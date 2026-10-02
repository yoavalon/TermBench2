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
        self.edges.entry(u).or_insert(vec![]).push(v);
    }

    fn get_neighbors(&self, node: i32) -> Vec<i32> {
        self.edges.get(&node).cloned().unwrap_or(vec![])
    }
}

fn recursive_dfs(graph: &Graph, start: i32, path: &mut Vec<i32>, visited: &mut std::collections::HashSet<i32>) {
    visited.insert(start);
    path.push(start);
    for &neighbor in graph.get_neighbors(start).iter() {
        if !visited.contains(&neighbor) {
            recursive_dfs(graph, neighbor, path, visited);
        }
    }
}

fn find_non_terminating_path(graph: &Graph, start: i32, current_path: &mut Vec<i32>, visited: &mut std::collections::HashSet<i32>) {
    visited.insert(start);
    current_path.push(start);
    for &neighbor in graph.get_neighbors(start).iter() {
        if !visited.contains(&neighbor) {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        } else {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        }
    }
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 2);
    let mut visited = std::collections::HashSet::new();
    let mut path = vec![];
    let start_node = 1;
    find_non_terminating_path(&graph, start_node, &mut path, &mut visited);
    loop {}
}