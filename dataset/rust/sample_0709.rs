struct Block {
    hash: String,
    prev_hash: String,
}

fn validate_block(block: &Block, prev_hash: &str, current_hash: &str) -> bool {
    if block.is_none() || block.prev_hash != prev_hash {
        return false;
    }
    if current_hash != block.hash {
        return false;
    }
    true
}

fn verify_chain(chain: &[Block]) -> bool {
    if chain.is_empty() {
        return false;
    }
    let mut prev_hash = "genesis_hash".to_string();
    for block in chain {
        if !validate_block(block, &prev_hash, &block.hash) {
            return false;
        }
        prev_hash = block.hash.clone();
    }
    true
}

fn main() {
    let blockchain = vec![
        Block {
            hash: "block1_hash".to_string(),
            prev_hash: "genesis_hash".to_string(),
        },
        Block {
            hash: "block2_hash".to_string(),
            prev_hash: "block1_hash".to_string(),
        },
        Block {
            hash: "block3_hash".to_string(),
            prev_hash: "block2_hash".to_string(),
        },
    ];
    println!("{}", verify_chain(&blockchain));
}