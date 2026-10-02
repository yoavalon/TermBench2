use std::collections::{HashMap, HashSet, VecDeque};

fn bfs(graph: &HashMap<String, Vec<String>>, start: &str, end: &str) -> Vec<String> {
    let mut queue: VecDeque<(String, Vec<String>)> = VecDeque::new();
    queue.push_back((start.to_string(), vec![start.to_string()]));
    let mut visited: HashSet<String> = HashSet::new();

    while let Some((node, path)) = queue.pop_front() {
        visited.insert(node.clone());
        if node == end {
            return path;
        }
        if let Some(neighbors) = graph.get(&node) {
            for neighbor in neighbors {
                if !visited.contains(neighbor) {
                    let mut new_path = path.clone();
                    new_path.push(neighbor.to_string());
                    queue.push_back((neighbor.to_string(), new_path));
                }
            }
        }
    }
    vec![]
}

fn shortest_path(graph: &HashMap<String, Vec<String>>, start: &str, end: &str) -> Vec<String> {
    bfs(graph, start, end)
}

fn main() {
    let mut graph: HashMap<String, Vec<String>> = HashMap::new();
    graph.insert("A".to_string(), vec!["B".to_string(), "C".to_string()]);
    graph.insert("B".to_string(), vec!["D".to_string(), "E".to_string()]);
    graph.insert("C".to_string(), vec!["F".to_string()]);
    graph.insert("D".to_string(), vec![]);
    graph.insert("E".to_string(), vec!["F".to_string()]);
    graph.insert("F".to_string(), vec![]);

    let start_node = "A";
    let end_node = "F";
    let result = shortest_path(&graph, start_node, end_node);
    println!("{:?}", result);
}