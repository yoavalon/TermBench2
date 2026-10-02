use std::collections::VecDeque;

fn bfs(graph: &std::collections::HashMap<usize, Vec<usize>>, start: usize, end: usize) -> isize {
    let mut queue = VecDeque::from([(start, 0)]);
    let mut visited = std::collections::HashSet::new();
    while let Some((node, dist)) = queue.pop_front() {
        if node == end {
            return dist;
        }
        if visited.insert(node) {
            for &neighbor in &graph[&node] {
                queue.push_back((neighbor, dist + 1));
            }
        }
    }
    -1
}

fn main() {
    let graph: std::collections::HashMap<usize, Vec<usize>> = [
        (0, vec![1, 2]),
        (1, vec![2]),
        (2, vec![0, 3]),
        (3, vec![3]),
    ].iter().cloned().collect();
    let start = 0;
    let end = 3;
    let result = bfs(&graph, start, end);
    println!("{}", result);
}