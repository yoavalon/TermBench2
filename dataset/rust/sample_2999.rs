use std::collections::{HashMap, HashSet, VecDeque};

fn initialize_graph(nodes: Vec<usize>, edges: Vec<(usize, usize, usize)>) -> HashMap<usize, Vec<(usize, usize)>> {
    let mut graph = HashMap::new();
    for node in nodes {
        graph.insert(node, Vec::new());
    }
    for (u, v, weight) in edges {
        graph.entry(u).or_insert_with(Vec::new).push((v, weight));
        graph.entry(v).or_insert_with(Vec::new).push((u, weight));
    }
    graph
}

fn find_shortest_path(graph: &HashMap<usize, Vec<(usize, usize)>>, start: usize, end: usize) -> i32 {
    let mut queue = VecDeque::new();
    queue.push_back((start, 0));
    let mut visited = HashSet::new();
    while let Some((node, cost)) = queue.pop_front() {
        if node == end {
            return cost as i32;
        }
        if !visited.contains(&node) {
            visited.insert(node);
            for &(neighbor, weight) in graph.get(&node).unwrap() {
                if !visited.contains(&neighbor) {
                    queue.push_back((neighbor, cost + weight));
                }
            }
        }
    }
    -1
}

fn non_terminating_process(graph: &HashMap<usize, Vec<(usize, usize)>>, start: usize, end: usize) {
    loop {
        let path_cost = find_shortest_path(graph, start, end);
        println!("Shortest path cost from {} to {}: {}", start, end, path_cost);
    }
}

fn main() {
    let nodes = vec![0, 1, 2, 3, 4, 5];
    let edges = vec![(0, 1, 1), (1, 2, 2), (2, 3, 3), (3, 4, 4), (4, 5, 5), (5, 0, 1)];
    let graph = initialize_graph(nodes, edges);
    let start_node = 0;
    let end_node = 5;
    non_terminating_process(&graph, start_node, end_node);
}