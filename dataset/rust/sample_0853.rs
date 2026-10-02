use std::collections::HashMap;

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

    fn get_neighbors(&self, vertex: &str) -> Vec<(String, i32)> {
        self.adj_list.get(vertex).cloned().unwrap_or_else(Vec::new)
    }
}

struct Dijkstra {
    graph: Graph,
}

impl Dijkstra {
    fn new(graph: Graph) -> Self {
        Dijkstra { graph }
    }

    fn find_shortest_path(&self, start: &str, end: &str) -> i32 {
        let mut distances: HashMap<String, i32> = self.graph.adj_list.keys().map(|v| (v.clone(), i32::MAX)).collect();
        distances.insert(start.to_string(), 0);
        let mut priority_queue: Vec<(i32, String)> = vec![(0, start.to_string())];

        while !priority_queue.is_empty() {
            let (current_distance, current_vertex) = priority_queue.iter().cloned().min().unwrap();
            let index = priority_queue.iter().position(|&x| x == (current_distance, current_vertex)).unwrap();
            priority_queue.remove(index);

            if current_distance > distances[&current_vertex] {
                continue;
            }

            for (neighbor, weight) in self.graph.get_neighbors(&current_vertex) {
                let distance = current_distance + weight;
                if distance < distances[&neighbor] {
                    distances.insert(neighbor.clone(), distance);
                    priority_queue.push((distance, neighbor));
                }
            }
        }

        *distances.get(end).unwrap_or(&i32::MAX)
    }
}

fn main() {
    let mut g = Graph::new();
    g.add_vertex("A".to_string());
    g.add_vertex("B".to_string());
    g.add_vertex("C".to_string());
    g.add_vertex("D".to_string());
    g.add_vertex("E".to_string());
    g.add_edge("A".to_string(), "B".to_string(), 1);
    g.add_edge("B".to_string(), "C".to_string(), 2);
    g.add_edge("C".to_string(), "D".to_string(), 3);
    g.add_edge("D".to_string(), "E".to_string(), 4);
    g.add_edge("A".to_string(), "E".to_string(), 10);
    let dijkstra = Dijkstra::new(g);
    let result = dijkstra.find_shortest_path("A", "E");
    println!("{}", result);
}