struct Graph {
    nodes: Vec<i32>,
    edges: Vec<(i32, i32)>,
}

impl Graph {
    fn new(nodes: Vec<i32>, edges: Vec<(i32, i32)>) -> Self {
        Graph { nodes, edges }
    }

    fn get_neighbors(&self, node: i32) -> Vec<i32> {
        let mut neighbors = Vec::new();
        for &(a, b) in &self.edges {
            if a == node {
                neighbors.push(b);
            } else if b == node {
                neighbors.push(a);
            }
        }
        neighbors
    }
}

struct Queue {
    items: Vec<(i32, Vec<i32>)>,
}

impl Queue {
    fn new() -> Self {
        Queue { items: Vec::new() }
    }

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }

    fn enqueue(&mut self, item: (i32, Vec<i32>)) {
        self.items.push(item);
    }

    fn dequeue(&mut self) -> (i32, Vec<i32>) {
        self.items.remove(0)
    }
}

fn bfs(graph: &Graph, start: i32, goal: i32) -> Option<Vec<i32>> {
    let mut queue = Queue::new();
    queue.enqueue((start, vec![start]));
    let mut visited = std::collections::HashSet::new();

    while !queue.is_empty() {
        let (node, path) = queue.dequeue();
        if node == goal {
            return Some(path);
        }
        if visited.insert(node) {
            for &neighbor in graph.get_neighbors(node).iter() {
                if !visited.contains(&neighbor) {
                    queue.enqueue((neighbor, path.clone().into_iter().chain(Some(neighbor)).collect()));
                }
            }
        }
    }
    None
}

fn main() {
    let nodes = vec![1, 2, 3, 4, 5];
    let edges = vec![(1, 2), (1, 3), (2, 4), (3, 4), (4, 5)];
    let graph = Graph::new(nodes, edges);
    let start_node = 1;
    let goal_node = 5;
    match bfs(&graph, start_node, goal_node) {
        Some(result) => println!("{:?}", result),
        None => println!("No path found"),
    }
}