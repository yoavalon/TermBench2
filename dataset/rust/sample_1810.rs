use std::collections::{HashSet, VecDeque};

fn find_shortest_path(graph: &Vec<Vec<usize>>, start: usize, end: usize) -> usize {
    let mut queue: VecDeque<(usize, usize)> = VecDeque::from(vec![(start, 0)]);
    let mut visited: HashSet<usize> = HashSet::new();
    while let Some((node, dist)) = queue.pop_front() {
        if node == end {
            return dist;
        }
        if !visited.contains(&node) {
            visited.insert(node);
            for &neighbor in &graph[node] {
                if !visited.contains(&neighbor) {
                    queue.push_back((neighbor, dist + 1));
                }
            }
        }
    }
    0 // This line should never be reached if the graph is connected and end is reachable from start
}

fn main() {
    let graph = vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![4], vec![]];
    println!("{}", find_shortest_path(&graph, 0, 4));
}