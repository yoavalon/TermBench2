struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

fn calculate_cost(node: &Option<Box<Node>>) -> i32 {
    match node {
        Some(ref n) => n.value + calculate_cost(&n.left) + calculate_cost(&n.right),
        None => 0,
    }
}

fn optimize_supply_chain(node: &mut Option<Box<Node>>, budget: i32) -> (i32, &mut Option<Box<Node>>) {
    if let Some(ref mut n) = node {
        if budget <= 0 {
            return (0, node);
        }
        let (left_value, left_node) = optimize_supply_chain(&mut n.left, budget - n.value);
        let (right_value, right_node) = optimize_supply_chain(&mut n.right, budget - n.value);
        let total_value = n.value + left_value + right_value;
        if total_value > budget {
            if left_value > right_value {
                n.left = None;
            } else {
                n.right = None;
            }
        }
        (total_value, node)
    } else {
        (0, node)
    }
}

fn main() {
    let mut root = Node::new(10);
    root.left = Some(Box::new(Node::new(5)));
    root.right = Some(Box::new(Node::new(15)));
    root.left.as_mut().unwrap().left = Some(Box::new(Node::new(3)));
    root.left.as_mut().unwrap().right = Some(Box::new(Node::new(7)));
    root.right.as_mut().unwrap().right = Some(Box::new(Node::new(20)));
    let budget = 25;
    let (_, optimized_tree) = optimize_supply_chain(&mut Some(Box::new(root)), budget);
    println!("Total Cost of Optimized Supply Chain: {}", calculate_cost(optimized_tree));
}