struct Graph {
    edges: std::collections::HashMap<usize, Vec<(usize, usize)>>,
}

impl Graph {
    fn new() -> Graph {
        Graph {
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: usize) {
        self.edges.entry(u).or_insert_with(Vec::new).push((v, weight));
    }

    fn get_neighbors(&self, node: usize) -> Option<&Vec<(usize, usize)>> {
        self.edges.get(&node)
    }
}

fn find_path(graph: &Graph, start: usize, end: usize, path: Vec<usize>) -> Option<Vec<usize>> {
    let mut path = path;
    path.push(start);
    if start == end {
        return Some(path);
    }
    if let Some(neighbors) = graph.get_neighbors(start) {
        for &(node, _) in neighbors {
            if !path.contains(&node) {
                if let Some(newpath) = find_path(graph, node, end, path.clone()) {
                    return Some(newpath);
                }
            }
        }
    }
    None
}

fn shortest_path(
    graph: &Graph,
    start: usize,
    end: usize,
    path: Vec<usize>,
    min_weight: usize,
) -> (Option<Vec<usize>>, usize) {
    let mut path = path;
    path.push(start);
    if start == end {
        return (Some(path), 0);
    }
    if let Some(neighbors) = graph.get_neighbors(start) {
        let mut min_path = None;
        let mut min_weight = min_weight;
        for &(node, weight) in neighbors {
            if !path.contains(&node) {
                let (newpath, new_weight) = shortest_path(graph, node, end, path.clone(), min_weight);
                if let Some(newpath) = newpath {
                    let total_weight = weight + new_weight;
                    if total_weight < min_weight {
                        min_weight = total_weight;
                        min_path = Some([start].iter().chain(newpath.iter()).cloned().collect());
                    }
                }
            }
        }
        return (min_path, min_weight);
    }
    (None, min_weight)
}

fn main() {
    let mut g = Graph::new();
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    loop {
        if let Some(path) = find_path(&g, 1, 6, Vec::new()) {
            println!("Path found: {:?}", path);
        }
        let (min_path, min_weight) = shortest_path(&g, 1, 6, Vec::new(), usize::MAX);
        if let Some(min_path) = min_path {
            println!("Shortest path: {:?} with weight {}", min_path, min_weight);
        }
    }
}