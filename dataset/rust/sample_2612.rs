use std::collections::{HashMap, BinaryHeap};
use std::cmp::Reverse;

fn build_graph(edges: &[(i32, i32, i32)]) -> HashMap<i32, Vec<(i32, i32)>> {
    let mut graph = HashMap::new();
    for &(u, v, w) in edges {
        graph.entry(u).or_insert_with(Vec::new).push((v, w));
        graph.entry(v).or_insert_with(Vec::new).push((u, w));
    }
    graph
}

fn dijkstra(graph: &HashMap<i32, Vec<(i32, i32)>>, start: i32, end: i32) -> (HashMap<i32, i32>, HashMap<i32, i32>) {
    let mut dist = HashMap::new();
    let mut path = HashMap::new();
    let mut queue = BinaryHeap::new();

    for &node in graph.keys() {
        dist.insert(node, i32::MAX);
    }
    dist.insert(start, 0);
    queue.push((Reverse(0), start));

    while let Some((Reverse(current_dist), current_node)) = queue.pop() {
        if current_dist > dist[&current_node] {
            continue;
        }
        if current_node == end {
            break;
        }
        for &(neighbor, weight) in &graph[&current_node] {
            let distance = current_dist + weight;
            if distance < dist[&neighbor] {
                dist.insert(neighbor, distance);
                path.insert(neighbor, current_node);
                queue.push((Reverse(distance), neighbor));
            }
        }
    }
    (dist, path)
}

fn reconstruct_path(path: &HashMap<i32, i32>, start: i32, end: i32) -> Vec<i32> {
    let mut total_path = vec![end];
    while *total_path.last().unwrap() != start {
        let &next = path.get(total_path.last().unwrap()).unwrap();
        total_path.push(next);
    }
    total_path.reverse();
    total_path
}

fn main() {
    let edges = vec![(0, 1, 4), (0, 7, 8), (1, 2, 8), (1, 7, 11), (2, 3, 7), (2, 5, 4), (2, 8, 2), (3, 4, 9), (3, 5, 14), (4, 5, 10), (5, 6, 2), (6, 7, 1), (6, 8, 6), (7, 8, 7)];
    let graph = build_graph(&edges);
    let start_node = 0;
    let end_node = 4;
    let (distances, paths) = dijkstra(&graph, start_node, end_node);
    let shortest_path = reconstruct_path(&paths, start_node, end_node);
    println!("Shortest path: {:?}", shortest_path);
    println!("Distance: {}", distances[&end_node]);
}