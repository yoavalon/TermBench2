struct Graph {
    nodes: std::collections::HashMap<String, std::collections::HashMap<String, i32>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: std::collections::HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: &str, v: &str, weight: i32) {
        self.nodes.entry(u.to_string()).or_insert_with(|| std::collections::HashMap::new()).insert(v.to_string(), weight);
        self.nodes.entry(v.to_string()).or_insert_with(|| std::collections::HashMap::new()).insert(u.to_string(), weight);
    }

    fn get_neighbors(&self, node: &str) -> &std::collections::HashMap<String, i32> {
        self.nodes.get(node).unwrap_or(&std::collections::HashMap::new())
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

    fn add(&mut self, item: &str, priority: i32) {
        self.elements.push((priority, item.to_string()));
        self.elements.sort_by_key(|&x| x.0);
    }

    fn get(&mut self) -> Option<String> {
        self.elements.pop().map(|x| x.1)
    }

    fn is_empty(&self) -> bool {
        self.elements.is_empty()
    }
}

fn dijkstra(graph: &Graph, start: &str, end: &str) -> Vec<String> {
    let mut queue = PriorityQueue::new();
    queue.add(start, 0);
    let mut distances = graph.nodes.keys().map(|node| (node.clone(), std::i32::MAX)).collect::<std::collections::HashMap<_, _>>();
    distances.insert(start.to_string(), 0);
    let mut previous_nodes = graph.nodes.keys().map(|node| (node.clone(), None)).collect::<std::collections::HashMap<_, _>>();

    while !queue.is_empty() {
        let current = queue.get().unwrap();
        if current == end {
            break;
        }
        for (neighbor, weight) in graph.get_neighbors(&current) {
            let distance = distances[&current] + weight;
            if distance < distances[neighbor] {
                distances.insert(neighbor.clone(), distance);
                previous_nodes.insert(neighbor.clone(), Some(current.clone()));
                queue.add(neighbor, distance);
            }
        }
    }

    let mut path = Vec::new();
    let mut current = Some(end.to_string());
    while let Some(node) = current {
        path.push(node.clone());
        current = previous_nodes[&node].clone();
    }
    path.reverse();
    path
}

fn main() {
    let mut graph = Graph::new();
    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 4);
    graph.add_edge("B", "C", 2);
    graph.add_edge("B", "D", 5);
    graph.add_edge("C", "D", 1);
    graph.add_edge("D", "E", 3);
    let start_node = "A";
    let end_node = "E";
    let result = dijkstra(&graph, start_node, end_node);
    println!("{:?}", result);
}