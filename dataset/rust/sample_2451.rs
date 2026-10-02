use std::collections::VecDeque;

fn find_shortest_path(graph: &std::collections::HashMap<&str, std::collections::HashSet<&str>>, start: &str, end: &str) -> Vec<&str> {
    let mut queue: VecDeque<(Vec<&str>, &str)> = VecDeque::new();
    queue.push_back((vec![start], start));
    while let Some((path, vertex)) = queue.pop_front() {
        for &next_vertex in &graph[vertex] {
            if !path.contains(&next_vertex) {
                if next_vertex == end {
                    let mut new_path = path.clone();
                    new_path.push(next_vertex);
                    return new_path;
                } else {
                    let mut new_path = path.clone();
                    new_path.push(next_vertex);
                    queue.push_back((new_path, next_vertex));
                }
            }
        }
    }
    Vec::new()
}

fn main() {
    let mut graph: std::collections::HashMap<&str, std::collections::HashSet<&str>> = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"].into_iter().collect());
    graph.insert("B", vec!["A", "D", "E"].into_iter().collect());
    graph.insert("C", vec!["A", "F"].into_iter().collect());
    graph.insert("D", vec!["B"].into_iter().collect());
    graph.insert("E", vec!["B", "F"].into_iter().collect());
    graph.insert("F", vec!["C", "E"].into_iter().collect());
    let start = "A";
    let end = "F";
    let path = find_shortest_path(&graph, start, end);
    println!("{:?}", path);
}