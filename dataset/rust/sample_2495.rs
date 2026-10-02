use std::collections::{HashSet, VecDeque};

fn find_shortest_path(graph: &std::collections::HashMap<&str, Vec<&str>>, start: &str, end: &str) -> i32 {
    let mut q = VecDeque::new();
    q.push_back((start, 0));
    let mut v = HashSet::new();
    
    while let Some((n, d)) = q.pop_front() {
        if n == end {
            return d;
        }
        v.insert(n);
        for nxt in graph.get(n).unwrap_or(&vec![]) {
            if !v.contains(nxt) {
                q.push_back((nxt, d + 1));
            }
        }
    }
    -1
}

fn main() {
    let g: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["D", "E"]),
        ("C", vec!["F"]),
        ("D", vec!["G"]),
        ("E", vec!["F"]),
        ("F", vec!["G"]),
        ("G", vec![]),
    ].iter().cloned().collect();
    let result = find_shortest_path(&g, "A", "G");
    println!("{}", result);
}