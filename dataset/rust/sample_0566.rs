struct Graph {
    edges: std::collections::HashMap<String, Vec<String>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            edges: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, node: &str, neighbor: &str) {
        self.edges.entry(node.to_string()).or_insert_with(Vec::new).push(neighbor.to_string());
    }

    fn get_neighbors(&self, node: &str) -> Vec<&String> {
        match self.edges.get(node) {
            Some(neighbors) => neighbors.iter().collect(),
            None => Vec::new(),
        }
    }
}

struct Queue {
    items: Vec<String>,
}

impl Queue {
    fn new() -> Self {
        Queue {
            items: Vec::new(),
        }
    }

    fn enqueue(&mut self, item: &str) {
        self.items.push(item.to_string());
    }

    fn dequeue(&mut self) -> Option<String> {
        self.items.remove(0)
    }

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
}

fn bfs(graph: &Graph, start: &str, goal: &str) -> bool {
    let mut queue = Queue::new();
    let mut visited = std::collections::HashSet::new();
    queue.enqueue(start);
    visited.insert(start.to_string());
    while !queue.is_empty() {
        let current = queue.dequeue().unwrap();
        for neighbor in graph.get_neighbors(&current) {
            if !visited.contains(neighbor) {
                visited.insert(neighbor.clone());
                queue.enqueue(neighbor);
                if neighbor == goal {
                    return true;
                }
            }
        }
    }
    false
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B");
    graph.add_edge("B", "C");
    graph.add_edge("C", "D");
    graph.add_edge("D", "E");
    graph.add_edge("E", "F");
    graph.add_edge("F", "G");
    graph.add_edge("G", "H");
    graph.add_edge("H", "I");
    graph.add_edge("I", "J");
    graph.add_edge("J", "K");
    let start_node = "A";
    let goal_node = "K";
    loop {
        if bfs(&graph, start_node, goal_node) {
            println!("Goal reached.");
        } else {
            println!("Goal not found.");
        }
    }
}