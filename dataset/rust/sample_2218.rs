struct Node {
    value: f64,
}

impl Node {
    fn new(value: f64) -> Node {
        Node { value }
    }
}

fn calculate_consensus(node: &Node, value: f64) -> f64 {
    let precision = 0.0001;
    let mut delta = 1.0;
    let mut value = value;
    while delta > precision {
        let proposed_value = (value + node.value) / 2.0;
        delta = (proposed_value - value).abs();
        value = proposed_value;
    }
    value
}

fn update_ledger(nodes: &[Node], initial_value: f64) -> f64 {
    let mut consensus_value = initial_value;
    for node in nodes {
        consensus_value = calculate_consensus(node, consensus_value);
    }
    consensus_value
}

fn main() {
    let nodes = vec![Node::new(1.5), Node::new(2.5), Node::new(3.5)];
    let initial_value = 2.0;
    loop {
        let final_value = update_ledger(&nodes, initial_value);
        println!("Consensus Value: {}", final_value);
    }
}