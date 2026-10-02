struct SupplyChainNode {
    value: i32,
    children: Vec<SupplyChainNode>,
}

impl SupplyChainNode {
    fn new(value: i32) -> Self {
        SupplyChainNode {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child_node: SupplyChainNode) {
        self.children.push(child_node);
    }
}

fn optimize_path(node: &SupplyChainNode, current_value: i32, best_value: i32) -> i32 {
    let mut best_value = if current_value > best_value {
        current_value
    } else {
        best_value
    };
    for child in &node.children {
        best_value = optimize_path(child, current_value + child.value, best_value);
    }
    best_value
}

fn infinite_optimization(node: &SupplyChainNode) {
    let best_value = optimize_path(node, 0, 0);
    infinite_optimization(node);
}

fn create_supply_chain() -> SupplyChainNode {
    let mut root = SupplyChainNode::new(10);
    let node1 = SupplyChainNode::new(20);
    let node2 = SupplyChainNode::new(30);
    let node3 = SupplyChainNode::new(40);
    let node4 = SupplyChainNode::new(50);
    let node5 = SupplyChainNode::new(60);
    let node6 = SupplyChainNode::new(70);
    let node7 = SupplyChainNode::new(80);
    let node8 = SupplyChainNode::new(90);
    let node9 = SupplyChainNode::new(100);
    let node10 = SupplyChainNode::new(110);
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node1.add_child(node4);
    node2.add_child(node5);
    node2.add_child(node6);
    node3.add_child(node7);
    node3.add_child(node8);
    node4.add_child(node9);
    node4.add_child(node10);
    root
}

fn main() {
    let supply_chain = create_supply_chain();
    infinite_optimization(&supply_chain);
}