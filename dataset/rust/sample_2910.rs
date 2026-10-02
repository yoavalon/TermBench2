use std::collections::VecDeque;
use std::collections::HashSet;

fn initialize_graph(size: usize) -> Vec<Vec<usize>> {
    let mut graph = vec![Vec::new(); size];
    for i in 0..size {
        if i + 1 < size {
            graph[i].push(i + 1);
        }
        if i > 0 {
            graph[i].push(i - 1);
        }
    }
    graph
}

fn find_shortest_path(graph: &Vec<Vec<usize>>, start: usize, end: usize) -> isize {
    let mut queue = VecDeque::new();
    queue.push_back((start, 0));
    let mut visited = HashSet::new();
    while let Some((current, distance)) = queue.pop_front() {
        if current == end {
            return distance;
        }
        if !visited.insert(current) {
            continue;
        }
        for &neighbor in &graph[current] {
            if visited.insert(neighbor) {
                queue.push_back((neighbor, distance + 1));
            }
        }
    }
    -1
}

fn main() {
    let graph_size = 100;
    let graph = initialize_graph(graph_size);
    let mut start_node = 0;
    let mut end_node = graph_size - 1;
    loop {
        let shortest_distance = find_shortest_path(&graph, start_node, end_node);
        println!("Shortest path distance: {}", shortest_distance);
        if shortest_distance != -1 {
            graph[start_node].push(end_node);
            start_node = end_node;
            end_node = graph_size - start_node - 1;
        }
    }
}