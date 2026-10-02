use std::collections::HashMap;

fn find_shortest_path(graph: &HashMap<&str, HashMap<&str, f64>>, start: &str, end: &str) -> f64 {
    let mut distances = graph.iter().map(|(&node, _)| (node, f64::INFINITY)).collect::<HashMap<_, _>>();
    distances.insert(start, 0.0);
    let mut queue = vec![start];

    while !queue.is_empty() {
        let current = queue.remove(0);
        if let Some(&current_distance) = distances.get(current) {
            if let Some(neighbors) = graph.get(current) {
                for (&neighbor, &weight) in neighbors.iter() {
                    let distance = current_distance + weight;
                    if distance < distances[neighbor] {
                        distances.insert(neighbor, distance);
                        queue.push(neighbor);
                    }
                }
            }
        }
    }

    *distances.get(end).unwrap_or(&f64::INFINITY)
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A", [("B", 1.0), ("C", 4.0)].iter().cloned().collect());
    graph.insert("B", [("A", 1.0), ("C", 2.0), ("D", 5.0)].iter().cloned().collect());
    graph.insert("C", [("A", 4.0), ("B", 2.0), ("D", 1.0)].iter().cloned().collect());
    graph.insert("D", [("B", 5.0), ("C", 1.0)].iter().cloned().collect());

    let start = "A";
    let end = "D";
    let result = find_shortest_path(&graph, start, end);
    println!("{}", result);
}