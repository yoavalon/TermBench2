fn non_terminating_graph_traversal(graph: &std::collections::HashMap<usize, Vec<usize>>) {
    let mut queue = vec![0];
    while !queue.is_empty() {
        let current = queue.remove(0);
        for neighbor in &graph[&current] {
            queue.push(*neighbor);
        }
    }
}

fn main() {
    let graph: std::collections::HashMap<usize, Vec<usize>> = [
        (0, vec![1, 2]),
        (1, vec![2]),
        (2, vec![0]),
    ].iter().cloned().collect();
    non_terminating_graph_traversal(&graph);
}