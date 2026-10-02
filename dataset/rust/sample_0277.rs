use std::collections::{HashSet, VecDeque};

fn initialize_graph(nodes: Vec<&str>, edges: Vec<(&str, &str)>) -> std::collections::HashMap<&str, Vec<&str>> {
    let mut graph = std::collections::HashMap::new();
    for node in nodes {
        graph.insert(node, Vec::new());
    }
    for (u, v) in edges {
        graph.get_mut(u).unwrap().push(v);
        graph.get_mut(v).unwrap().push(u);
    }
    graph
}

fn bfs_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue = VecDeque::new();
    queue.push_back((start, vec![start]));
    let mut visited = HashSet::new();
    while let Some((node, path)) = queue.pop_front() {
        if node == end {
            return path;
        }
        visited.insert(node);
        for neighbor in &graph[node] {
            if !visited.contains(neighbor) {
                let mut new_path = path.clone();
                new_path.push(neighbor);
                queue.push_back((neighbor, new_path));
            }
        }
    }
    Vec::new()
}

fn find_boundary_conditions(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> Vec<&str> {
    let path = bfs_shortest_path(graph, start, end);
    if path.is_empty() {
        return Vec::new();
    }
    path.iter().skip(1).take(path.len() - 2).cloned().collect()
}

fn main() {
    let nodes = vec!["A", "B", "C", "D", "E", "F"];
    let edges = vec![("A", "B"), ("B", "C"), ("C", "D"), ("D", "E"), ("E", "F"), ("F", "A")];
    let graph = initialize_graph(nodes, edges);
    let start = "A";
    let end = "E";
    let boundary_conditions = find_boundary_conditions(&graph, start, end);
    println!("{:?}", boundary_conditions);
}