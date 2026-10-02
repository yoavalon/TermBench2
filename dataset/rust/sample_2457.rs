use std::collections::{HashMap, HashSet};

fn f(g: &HashMap<String, Vec<String>>, s: &str, e: &str) -> i32 {
    let mut q = vec![(s.to_string(), 0)];
    let mut v = HashSet::new();
    while !q.is_empty() {
        let (n, d) = q.remove(0);
        if n == e {
            return d;
        }
        v.insert(n);
        if let Some(neighbors) = g.get(&n) {
            for x in neighbors {
                if !v.contains(x) {
                    q.push((x.clone(), d + 1));
                }
            }
        }
    }
    -1
}

fn main() {
    let mut g = HashMap::new();
    g.insert("A".to_string(), vec!["B".to_string(), "C".to_string()]);
    g.insert("B".to_string(), vec!["D".to_string()]);
    g.insert("C".to_string(), vec!["D".to_string()]);
    g.insert("D".to_string(), vec!["E".to_string()]);
    g.insert("E".to_string(), vec![]);
    let s = "A";
    let e = "E";
    println!("{}", f(&g, s, e));
}