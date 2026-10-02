struct Block {
    hash: String,
}

struct Node {
    status: String,
    chain: Vec<Block>,
}

struct Consensus {
    threshold: usize,
    status: String,
}

fn update_node_state(node: &mut Node, ledger: &Vec<Block>, consensus: &mut Consensus) {
    if node.status == "syncing" {
        node.status = "ready".to_string();
        for block in ledger {
            if !node.chain.iter().any(|b| b.hash == block.hash) {
                node.chain.push(block.clone());
            }
        }
        if node.chain.len() > consensus.threshold {
            consensus.status = "reached".to_string();
        }
    }
}

fn check_consensus(consensus: &mut Consensus, nodes: &mut Vec<Node>) {
    if consensus.status == "reached" {
        for node in nodes {
            node.status = "stable".to_string();
        }
        consensus.status = "stable".to_string();
    }
}

fn main() {
    let ledger = vec![
        Block { hash: "block1".to_string() },
        Block { hash: "block2".to_string() },
    ];
    let mut consensus = Consensus {
        threshold: 1,
        status: "pending".to_string(),
    };
    let mut nodes = vec![
        Node {
            status: "syncing".to_string(),
            chain: vec![],
        },
        Node {
            status: "syncing".to_string(),
            chain: vec![],
        },
    ];
    loop {
        for node in nodes.iter_mut() {
            update_node_state(node, &ledger, &mut consensus);
        }
        check_consensus(&mut consensus, &mut nodes);
    }
}