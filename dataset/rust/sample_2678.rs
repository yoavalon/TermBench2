use std::collections::HashMap;
use std::cmp::Ordering;

struct Graph {
    adj_list: HashMap<String, Vec<(String, i32)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            adj_list: HashMap::new(),
        }
    }

    fn add_vertex(&mut self, vertex: String) {
        if !self.adj_list.contains_key(&vertex) {
            self.adj_list.insert(vertex, Vec::new());
        }
    }

    fn add_edge(&mut self, vertex1: String, vertex2: String, weight: i32) {
        if self.adj_list.contains_key(&vertex1) && self.adj_list.contains_key(&vertex2) {
            self.adj_list.get_mut(&vertex1).unwrap().push((vertex2.clone(), weight));
            self.adj_list.get_mut(&vertex2).unwrap().push((vertex1, weight));
        }
    }

    fn get_neighbors(&self, vertex: &String) -> Vec<(String, i32)> {
        self.adj_list.get(vertex).cloned().unwrap_or_else(Vec::new)
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

    fn empty(&self) -> bool {
        self.elements.is_empty()
    }

    fn put(&mut self, item: String, priority: i32) {
        self.elements.push((priority, item));
        self.elements.sort_by(|a, b| a.0.cmp(&b.0));
    }

    fn get(&mut self) -> String {
        self.elements.remove(0).1
    }
}

fn dijkstra(graph: &Graph, start: String, end: String) -> (Vec<String>, HashMap<String, i32>) {
    let mut queue = PriorityQueue::new();
    queue.put(start.clone(), 0);
    let mut distances = graph.adj_list.keys().map(|v| (v.clone(), i32::MAX)).collect::<HashMap<_, _>>();
    distances.insert(start.clone(), 0);
    let mut previous = graph.adj_list.keys().map(|v| (v.clone(), None)).collect::<HashMap<_, _>>();

    while !queue.empty() {
        let current = queue.get();
        if current == end {
            break;
        }
        for (neighbor, weight) in graph.get_neighbors(&current) {
            let distance = distances[&current] + weight;
            if distance < distances[&neighbor] {
                distances.insert(neighbor.clone(), distance);
                previous.insert(neighbor.clone(), Some(current.clone()));
                queue.put(neighbor, distance);
            }
        }
    }

    let mut path = Vec::new();
    let mut current = Some(end);
    while let Some(vertex) = current {
        path.push(vertex.clone());
        current = previous[&vertex].clone();
    }

    (path, distances)
}

fn main() {
    let mut graph = Graph::new();
    let vertices = vec!["A", "B", "C", "D", "E"];
    for vertex in vertices {
        graph.add_vertex(vertex.to_string());
    }
    graph.add_edge("A".to_string(), "B".to_string(), 1);
    graph.add_edge("B".to_string(), "C".to_string(), 2);
    graph.add_edge("C".to_string(), "D".to_string(), 3);
    graph.add_edge("D".to_string(), "E".to_string(), 4);
    graph.add_edge("E".to_string(), "A".to_string(), 5);
    let (path, distances) = dijkstra(&graph, "A".to_string(), "E".to_string());
    println!("Path: {:?}", path.iter().rev().collect::<Vec<_>>());
    println!("Distances: {:?}", distances);
}