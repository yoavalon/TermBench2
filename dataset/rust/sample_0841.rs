struct Node {
    value: i32,
    children: Vec<Node>,
}

impl Node {
    fn new(value: i32, children: Option<Vec<Node>>) -> Self {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }

    fn add_child(&mut self, child: Node) {
        self.children.push(child);
    }
}

fn calculate_cost(node: &Node, current_cost: i32) -> i32 {
    if node.children.is_empty() {
        return current_cost + node.value;
    }
    let mut total_cost = current_cost + node.value;
    for child in &node.children {
        total_cost += calculate_cost(child, current_cost + node.value);
    }
    total_cost
}

fn optimize_supply_chain(root: &Node) -> i32 {
    if root.children.is_empty() {
        return root.value;
    }
    let mut min_cost = i32::MAX;
    for child in &root.children {
        let cost = calculate_cost(child, 0);
        if cost < min_cost {
            min_cost = cost;
        }
    }
    min_cost
}

fn main() {
    let mut root = Node::new(10, None);
    let mut child1 = Node::new(5, None);
    let mut child2 = Node::new(15, None);
    let mut child3 = Node::new(20, None);
    let mut child4 = Node::new(25, None);
    child1.add_child(Node::new(30, None));
    child1.add_child(Node::new(35, None));
    child2.add_child(Node::new(40, None));
    child3.add_child(Node::new(45, None));
    child4.add_child(Node::new(50, None));
    root.add_child(child1);
    root.add_child(child2);
    root.add_child(child3);
    root.add_child(child4);
    let optimal_cost = optimize_supply_chain(&root);
    println!("{}", optimal_cost);
}