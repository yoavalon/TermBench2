use std::collections::VecDeque;

struct Graph {
    nodes: Vec<i32>,
    adj_list: Vec<Vec<i32>>,
}

impl Graph {
    fn new(nodes: Vec<i32>) -> Self {
        let adj_list = vec![Vec::new(); nodes.len()];
        Graph { nodes, adj_list }
    }

    fn add_edge(&mut self, node1: i32, node2: i32) {
        let index1 = self.nodes.iter().position(|&r| r == node1).unwrap();
        let index2 = self.nodes.iter().position(|&r| r == node2).unwrap();
        self.adj_list[index1].push(node2);
        self.adj_list[index2].push(node1);
    }
}

struct ShortestPathFinder {
    graph: Graph,
}

impl ShortestPathFinder {
    fn new(graph: Graph) -> Self {
        ShortestPathFinder { graph }
    }

    fn bfs(&self, start: i32, end: i32) -> i32 {
        let mut queue = VecDeque::from([(start, 0)]);
        let mut visited = vec![false; self.graph.nodes.len()];
        while let Some((node, dist)) = queue.pop_front() {
            if node == end {
                return dist;
            }
            let index = self.graph.nodes.iter().position(|&r| r == node).unwrap();
            if !visited[index] {
                visited[index] = true;
                for &neighbor in &self.graph.adj_list[index] {
                    queue.push_back((neighbor, dist + 1));
                }
            }
        }
        -1
    }
}

fn main() {
    let nodes = vec![0, 1, 2, 3, 4, 5, 6];
    let mut graph = Graph::new(nodes);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(0, 3);
    graph.add_edge(3, 6);
    let spf = ShortestPathFinder::new(graph);
    let result = spf.bfs(0, 6);
    println!("{}", result);
}