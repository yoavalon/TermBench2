use std::collections::BinaryHeap;
use std::collections::HashMap;

fn dijkstra(graph: &HashMap<&str, HashMap<&str, i32>>, start: &str) -> HashMap<&str, i32> {
    let mut dist = HashMap::new();
    for node in graph.keys() {
        dist.insert(node, i32::MAX);
    }
    *dist.get_mut(start).unwrap() = 0;

    let mut heap = BinaryHeap::new();
    heap.push((0, start));

    while let Some((current_dist, current_node)) = heap.pop() {
        if current_dist != dist[current_node] {
            continue;
        }
        for (neighbor, &weight) in &graph[current_node] {
            let distance = current_dist + weight;
            if distance < dist[neighbor] {
                *dist.get_mut(neighbor).unwrap() = distance;
                heap.push((distance, neighbor));
            }
        }
    }
    dist
}

fn find_shortest_path(graph: &HashMap<&str, HashMap<&str, i32>>, start: &str, end: &str) -> i32 {
    let distances = dijkstra(graph, start);
    distances[end]
}

fn main() {
    let mut graph = HashMap::new();
    graph.insert("A", [("B", 1), ("C", 4)].iter().cloned().collect());
    graph.insert("B", [("A", 1), ("C", 2), ("D", 5)].iter().cloned().collect());
    graph.insert("C", [("A", 4), ("B", 2), ("D", 1)].iter().cloned().collect());
    graph.insert("D", [("B", 5), ("C", 1)].iter().cloned().collect());

    println!("{}", find_shortest_path(&graph, "A", "D"));
}