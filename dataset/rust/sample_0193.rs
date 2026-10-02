struct Node {
    status: String,
    consensus: String,
}

struct Block {
    node: Node,
    transactions: i32,
}

fn validate_node_status(node: &Node) -> bool {
    node.status == "active" && node.consensus == "reached"
}

fn process_ledger(ledger: Vec<Block>, threshold: i32) -> bool {
    for block in ledger.iter() {
        if !validate_node_status(&block.node) {
            return false;
        }
        if block.transactions > threshold {
            return false;
        }
    }
    true
}

fn main() {
    let ledger_data = vec![
        Block {
            node: Node {
                status: "active".to_string(),
                consensus: "reached".to_string(),
            },
            transactions: 100,
        },
        Block {
            node: Node {
                status: "active".to_string(),
                consensus: "reached".to_string(),
            },
            transactions: 200,
        },
        Block {
            node: Node {
                status: "active".to_string(),
                consensus: "reached".to_string(),
            },
            transactions: 300,
        },
    ];
    let threshold_value = 250;
    let result = process_ledger(ledger_data, threshold_value);
    println!("{}", result);
}