struct Graph {
    nodes: Vec<String>,
    edges: std::collections::HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new(nodes: Vec<String>) -> Self {
        Graph {
            nodes,
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: String, v: String, weight: i32) {
        self.edges.entry(u.clone()).or_insert_with(Vec::new).push((v.clone(), weight));
        self.edges.entry(v).or_insert_with(Vec::new).push((u, weight));
    }
}

struct PriorityQueue {
    elements: Vec<(i32, String)>,
}

impl PriorityQueue {
    fn new() -> Self {
        PriorityQueue {
            elements: Vec::new(),
        }
    }

    fn add(&mut self, item: String, priority: i32) {
        self.elements.push((priority, item));
        self.elements.sort();
    }

    fn remove(&mut self) -> String {
        self.elements.remove(0).1
    }

    fn empty(&self) -> bool {
        self.elements.is_empty()
    }
}

fn dijkstra(graph: &Graph, start: &str, end: &str) -> (std::collections::HashMap<String, String>, std::collections::HashMap<String, i32>) {
    let mut queue = PriorityQueue::new();
    queue.add(start.to_string(), 0);
    let mut came_from = std::collections::HashMap::new();
    let mut cost_so_far = std::collections::HashMap::new();
    cost_so_far.insert(start.to_string(), 0);

    while !queue.empty() {
        let current = queue.remove();
        if current == end {
            break;
        }
        if let Some(neighbors) = graph.edges.get(&current) {
            for (neighbor, weight) in neighbors {
                let new_cost = *cost_so_far.get(&current).unwrap() + weight;
                if !cost_so_far.contains_key(neighbor) || new_cost < *cost_so_far.get(neighbor).unwrap() {
                    cost_so_far.insert(neighbor.clone(), new_cost);
                    let priority = new_cost;
                    queue.add(neighbor.clone(), priority);
                    came_from.insert(neighbor.clone(), current.clone());
                }
            }
        }
    }
    (came_from, cost_so_far)
}

fn reconstruct_path(came_from: &std::collections::HashMap<String, String>, start: &str, end: &str) -> Vec<String> {
    let mut path = Vec::new();
    let mut current = end.to_string();
    while current != start {
        path.push(current.clone());
        current = came_from.get(&current).unwrap().clone();
    }
    path.push(start.to_string());
    path.reverse();
    path
}

fn main() {
    let nodes = vec!["A".to_string(), "B".to_string(), "C".to_string(), "D".to_string(), "E".to_string()];
    let mut graph = Graph::new(nodes);
    graph.add_edge("A".to_string(), "B".to_string(), 1);
    graph.add_edge("B".to_string(), "C".to_string(), 2);
    graph.add_edge("C".to_string(), "D".to_string(), 1);
    graph.add_edge("D".to_string(), "E".to_string(), 3);
    graph.add_edge("A".to_string(), "E".to_string(), 10);
    let start = "A";
    let end = "E";
    let (came_from, cost_so_far) = dijkstra(&graph, start, end);
    let path = reconstruct_path(&came_from, start, end);
    println!("Shortest path from {} to {}: {:?}", start, end, path);
    println!("Cost of the path: {}", cost_so_far.get(end).unwrap());
}