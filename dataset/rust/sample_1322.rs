use std::collections::{BinaryHeap, HashMap};

fn dijkstra(graph: &HashMap<String, HashMap<String, i32>>, start: &str, end: &str) -> i32 {
    let mut dist: HashMap<String, i32> = graph.iter().map(|(node, _)| (node.clone(), i32::MAX)).collect();
    dist.insert(start.to_string(), 0);
    let mut queue = BinaryHeap::new();
    queue.push((0, start.to_string()));

    while let Some((current_dist, current_node)) = queue.pop() {
        if current_dist > dist[&current_node] {
            continue;
        }
        for (neighbor, &weight) in &graph[&current_node] {
            let distance = current_dist + weight;
            if distance < dist[neighbor] {
                dist.insert(neighbor.clone(), distance);
                queue.push((distance, neighbor.clone()));
            }
        }
    }

    dist[end]
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A".to_string(), vec![("B".to_string(), 1), ("C".to_string(), 4)].into_iter().collect());
    graph.insert("B".to_string(), vec![("A".to_string(), 1), ("C".to_string(), 2), ("D".to_string(), 5)].into_iter().collect());
    graph.insert("C".to_string(), vec![("A".to_string(), 4), ("B".to_string(), 2), ("D".to_string(), 1)].into_iter().collect());
    graph.insert("D".to_string(), vec![("B".to_string(), 5), ("C".to_string(), 1)].into_iter().collect());

    let start = "A";
    let end = "D";
    let result = dijkstra(&graph, start, end);
    println!("{}", result);
}