use std::collections::{BinaryHeap, HashMap};

struct Graph {
    graph: HashMap<usize, Vec<(usize, usize)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            graph: HashMap::new(),
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, weight: usize) {
        self.graph.entry(u).or_insert_with(Vec::new).push((v, weight));
        self.graph.entry(v).or_insert_with(Vec::new).push((u, weight));
    }
}

fn dijkstra(graph: &Graph, start: usize) -> HashMap<usize, usize> {
    let mut distances = graph.graph.keys().map(|&node| (node, usize::MAX)).collect::<HashMap<_, _>>();
    distances.insert(start, 0);

    let mut priority_queue = BinaryHeap::new();
    priority_queue.push((std::cmp::Reverse(0), start));

    while let Some((std::cmp::Reverse(current_distance), current_node)) = priority_queue.pop() {
        if current_distance > distances[&current_node] {
            continue;
        }
        if let Some(&neighbors) = graph.graph.get(&current_node) {
            for &(neighbor, weight) in neighbors {
                let distance = current_distance + weight;
                if distance < distances[&neighbor] {
                    distances.insert(neighbor, distance);
                    priority_queue.push((std::cmp::Reverse(distance), neighbor));
                }
            }
        }
    }

    distances
}

fn find_shortest_path(graph: &Graph, start: usize, end: usize) -> usize {
    let distances = dijkstra(graph, start);
    *distances.get(&end).unwrap_or(&usize::MAX)
}

fn main() {
    let mut g = Graph::new();
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 5, 4);
    g.add_edge(2, 8, 2);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    let shortest_path = find_shortest_path(&g, 0, 4);
    println!("{}", shortest_path);
}