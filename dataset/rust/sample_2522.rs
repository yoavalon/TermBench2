use std::collections::VecDeque;

fn bfs(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, goal: &str) -> Option<Vec<&str>> {
    let mut queue = VecDeque::new();
    queue.push_back((start, vec![start]));
    while let Some((vertex, path)) = queue.pop_front() {
        for next in graph.get(vertex).unwrap_or(&vec![]).iter().filter(|&&x| !path.contains(&x)) {
            if *next == goal {
                return Some(path.into_iter().chain(std::iter::once(next)).collect());
            } else {
                let mut new_path = path.clone();
                new_path.push(next);
                queue.push_back((next, new_path));
            }
        }
    }
    None
}

fn find_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, goal: &str) -> Vec<&str> {
    if let Some(path) = bfs(graph, start, goal) {
        path
    } else {
        vec![]
    }
}

fn main() {
    let mut graph = std::collections::HashMap::new();
    graph.insert("A", vec!["B", "C"]);
    graph.insert("B", vec!["D", "E"]);
    graph.insert("C", vec!["F"]);
    graph.insert("D", vec![]);
    graph.insert("E", vec!["F"]);
    graph.insert("F", vec![]);
    let start_node = "A";
    let goal_node = "F";
    let result = find_path(&graph, start_node, goal_node);
    println!("{:?}", result);
}