use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

fn validate_blockchain(blockchain: &Vec<&[u8]>, index: usize) -> bool {
    if index >= blockchain.len() {
        return true;
    }
    let prev_block = if index > 0 { blockchain[index - 1] } else { b"" };
    let mut hasher = DefaultHasher::new();
    prev_block.hash(&mut hasher);
    let prev_hash = hasher.finish();
    let mut hasher = DefaultHasher::new();
    blockchain[index].hash(&mut hasher);
    let current_hash = hasher.finish();
    if current_hash != prev_hash {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

fn append_block(blockchain: &mut Vec<&[u8]>, new_block: &[u8]) {
    if validate_blockchain(blockchain, 0) {
        blockchain.push(new_block);
    }
}

fn main() {
    let mut blockchain = vec![b"genesis"];
    append_block(&mut blockchain, b"block1");
    append_block(&mut blockchain, b"block2");
    println!("{}", validate_blockchain(&blockchain, 0));
}