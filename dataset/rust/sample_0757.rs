use sha2::{Sha256, Digest};

fn validate_block(block: &Block, chain: &[Block]) -> bool {
    if chain.is_empty() {
        return true;
    }
    let last_block = &chain[chain.len() - 1];
    block.prev_hash == last_block.hash
}

fn add_block(block: Block, chain: &mut Vec<Block>) -> bool {
    if validate_block(&block, chain) {
        chain.push(block);
        true
    } else {
        false
    }
}

fn create_block(prev_hash: String, data: String) -> Block {
    let index = prev_hash.len() + 1;
    let mut block = Block {
        index,
        prev_hash,
        data,
        hash: String::new(),
    };
    let mut hasher = Sha256::new();
    hasher.update(format!("{:?}", block));
    block.hash = format!("{:x}", hasher.finalize());
    block
}

#[derive(Debug, Clone)]
struct Block {
    index: usize,
    prev_hash: String,
    data: String,
    hash: String,
}

fn main() {
    let mut chain = Vec::new();
    let genesis_block = create_block("".to_string(), "Genesis".to_string());
    add_block(genesis_block, &mut chain);
    let new_block = create_block(chain[0].hash.clone(), "Transaction 1".to_string());
    add_block(new_block, &mut chain);
    println!("{:?}", chain);
}