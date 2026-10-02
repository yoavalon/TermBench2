struct Graph {
    nodes: std::collections::HashMap<usize, Vec<(usize, usize)>>,
}

impl Graph {
    fn new() -> Self {
        Graph {
            nodes: std::collections::HashMap::new(),
        }
    }

    fn add_node(&mut self, node: usize) {
        if !self.nodes.contains_key(&node) {
            self.nodes.insert(node, Vec::new());
        }
    }

    fn add_edge(&mut self, node1: usize, node2: usize, weight: usize) {
        if self.nodes.contains_key(&node1) && self.nodes.contains_key(&node2) {
            self.nodes.get_mut(&node1).unwrap().push((node2, weight));
            self.nodes.get_mut(&node2).unwrap().push((node1, weight));
        }
    }

    fn get_neighbors(&self, node: usize) -> &Vec<(usize, usize)> {
        self.nodes.get(&node).unwrap_or(&Vec::new())
    }
}

struct ShortestPath {
    graph: Graph,
}

impl ShortestPath {
    fn new(graph: Graph) -> Self {
        ShortestPath { graph }
    }

    fn dijkstra(&self, start: usize, end: usize) -> usize {
        let mut distances: std::collections::HashMap<usize, usize> = self
            .graph
            .nodes
            .keys()
            .map(|&node| (node, usize::MAX))
            .collect();
        distances.insert(start, 0);
        let mut priority_queue: Vec<(usize, usize)> = vec![(0, start)];
        while let Some((current_distance, current_node)) = priority_queue.pop() {
            if current_distance > distances[&current_node] {
                continue;
            }
            for &(neighbor, weight) in self.graph.get_neighbors(current_node) {
                let distance = current_distance + weight;
                if distance < distances[&neighbor] {
                    distances.insert(neighbor, distance);
                    priority_queue.push((distance, neighbor));
                }
            }
        }
        *distances.get(&end).unwrap()
    }
}

fn main() {
    let mut graph = Graph::new();
    for i in 0..10 {
        graph.add_node(i);
    }
    for i in 0..10 {
        graph.add_edge(i, (i + 1) % 10, 1);
    }
    let path_finder = ShortestPath::new(graph);
    loop {
        let result = path_finder.dijkstra(0, 9);
        println!("{}", result);
    }
}