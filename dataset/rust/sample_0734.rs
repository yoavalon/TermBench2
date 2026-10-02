use std::collections::HashSet;

fn optimize_route(routes: &std::collections::HashMap<String, std::collections::HashMap<String, i32>>, start: &str, end: &str, visited: Option<&mut HashSet<String>>, path: Option<&mut Vec<String>>) -> Option<Vec<String>> {
    let mut visited = visited.unwrap_or(&mut HashSet::new());
    let mut path = path.unwrap_or(&mut Vec::new());
    visited.insert(start.to_string());
    path.push(start.to_string());
    if start == end {
        return Some(path.clone());
    }
    if let Some(neighbors) = routes.get(start) {
        for (neighbor, _) in neighbors {
            if !visited.contains(neighbor) {
                let mut new_path = path.clone();
                if let Some(result) = optimize_route(routes, neighbor, end, Some(visited), Some(&mut new_path)) {
                    return Some(result);
                }
            }
        }
    }
    None
}

fn main() {
    let mut routes = std::collections::HashMap::new();
    routes.insert("A".to_string(), vec![("B".to_string(), 10), ("C".to_string(), 15)].into_iter().collect());
    routes.insert("B".to_string(), vec![("C".to_string(), 35), ("D".to_string(), 25)].into_iter().collect());
    routes.insert("C".to_string(), vec![("D".to_string(), 30)].into_iter().collect());
    routes.insert("D".to_string(), Vec::new().into_iter().collect());
    let start = "A";
    let end = "D";
    if let Some(optimal_path) = optimize_route(&routes, start, end, None, None) {
        println!("{:?}", optimal_path);
    }
}