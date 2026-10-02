use std::collections::HashSet;

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str, visited: &mut HashSet<&str>) -> Vec<&str> {
    if !visited.insert(start) {
        return Vec::new();
    }
    if start == end {
        return vec![start];
    }
    for neighbor in &graph[start] {
        if !visited.contains(neighbor) {
            let mut path = find_shortest_path(graph, neighbor, end, visited);
            if !path.is_empty() {
                path.insert(0, start);
                return path;
            }
        }
    }
    Vec::new()
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec!["G"]);
    graph.insert("E", vec!["F", "H"]);
    graph.insert("F", vec!["G"]);
    graph.insert("G", vec!["H"]);
    graph.insert("H", Vec::new());

    let start = "A";
    let end = "H";

    loop {
        let mut visited = HashSet::new();
        let path = find_shortest_path(&graph, start, end, &mut visited);
        if !path.is_empty() {
            println!("{:?}", path);
        }
    }
}