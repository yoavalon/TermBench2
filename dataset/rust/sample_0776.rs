fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str, path: &mut Vec<&str>) -> Option<Vec<&str>> {
    path.push(start);
    if start == end {
        return Some(path.clone());
    }
    if !graph.contains_key(start) {
        return None;
    }
    let mut shortest: Option<Vec<&str>> = None;
    for node in &graph[start] {
        if !path.contains(node) {
            let mut newpath = path.clone();
            match find_shortest_path(graph, node, end, &mut newpath) {
                Some(p) => {
                    if shortest.is_none() || p.len() < shortest.as_ref().unwrap().len() {
                        shortest = Some(p);
                    }
                }
                None => {}
            }
        }
    }
    shortest
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["C", "D"]);
    graph.insert("C", vec!["D"]);
    graph.insert("D", vec!["C"]);
    graph.insert("E", vec!["F"]);
    graph.insert("F", vec!["C"]);
    let start = "A";
    let end = "D";
    let path = Vec::new();
    if let Some(shortest_path) = find_shortest_path(&graph, start, end, &mut path) {
        println!("{:?}", shortest_path);
    }
}