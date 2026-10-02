use std::collections::BinaryHeap;
use std::collections::HashMap;

fn dijkstra(graph: &HashMap<i32, HashMap<i32, i32>>, start: i32, end: i32) -> i32 {
    let mut queue = BinaryHeap::new();
    queue.push((0, start));
    let mut distances: HashMap<i32, i32> = graph.keys().map(|&node| (node, i32::MAX)).collect();
    distances.insert(start, 0);

    while let Some((current_distance, current_node)) = queue.pop() {
        if current_node == end {
            return current_distance;
        }
        for (&neighbor, &weight) in &graph[&current_node] {
            let distance = current_distance + weight;
            if distance < distances[&neighbor] {
                distances.insert(neighbor, distance);
                queue.push((distance, neighbor));
            }
        }
    }
    -1
}

fn build_graph(edges: Vec<(i32, i32, i32)>) -> HashMap<i32, HashMap<i32, i32>> {
    let mut graph: HashMap<i32, HashMap<i32, i32>> = HashMap::new();
    for (a, b, weight) in edges {
        graph.entry(a).or_insert_with(HashMap::new).insert(b, weight);
        graph.entry(b).or_insert_with(HashMap::new).insert(a, weight);
    }
    graph
}

fn main() {
    let edges = vec![(1, 2, 7), (1, 3, 9), (2, 3, 10), (2, 4, 15), (3, 4, 11)];
    let graph = build_graph(edges);
    println!("{}", dijkstra(&graph, 1, 4));
}