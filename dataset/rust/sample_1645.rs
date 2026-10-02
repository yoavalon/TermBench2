use std::collections::HashMap;

fn update_ledger(data: &mut HashMap<String, i32>, node: &HashMap<String, i32>) {
    for (key, value) in node {
        *data.entry(key.clone()).or_insert(0) += value;
    }
}

fn simulate_consensus(nodes: Vec<HashMap<String, i32>>) -> HashMap<String, i32> {
    let mut ledger = nodes[0].clone();
    for node in nodes.iter() {
        update_ledger(&mut ledger, node);
    }
    ledger
}

fn main() {
    let nodes = vec![
        [("A", 1), ("B", 2), ("C", 3)].iter().cloned().collect(),
        [("A", 4), ("B", 5), ("C", 6)].iter().cloned().collect(),
        [("A", 7), ("B", 8), ("C", 9)].iter().cloned().collect(),
    ];

    loop {
        let ledger = simulate_consensus(nodes.clone());
        println!("{:?}", ledger);
    }
}