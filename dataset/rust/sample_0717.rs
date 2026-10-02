use std::collections::HashMap;
use sha2::{Sha256, Digest};

fn validate_block(block: &HashMap<String, String>, chain: &Vec<HashMap<String, String>>) -> bool {
    if chain.is_empty() {
        return true;
    }
    let last_block = &chain[chain.len() - 1];
    if block.get("prev_hash") != last_block.get("hash") {
        return false;
    }
    true
}

fn compute_hash(block: &HashMap<String, String>) -> String {
    let block_string = format!("{:?}", block);
    let mut hasher = Sha256::new();
    hasher.update(block_string);
    format!("{:x}", hasher.finalize())
}

fn add_block(block: HashMap<String, String>, chain: &mut Vec<HashMap<String, String>>) -> bool {
    let mut block_with_hash = block.clone();
    block_with_hash.insert("hash".to_string(), compute_hash(&block_with_hash));
    if validate_block(&block_with_hash, chain) {
        chain.push(block_with_hash);
        true
    } else {
        false
    }
}

fn create_chain() -> Vec<HashMap<String, String>> {
    Vec::new()
}

fn main() {
    let mut chain = create_chain();
    let mut block1 = HashMap::new();
    block1.insert("data".to_string(), "Tx1".to_string());
    block1.insert("prev_hash".to_string(), "".to_string());
    let mut block2 = HashMap::new();
    block2.insert("data".to_string(), "Tx2".to_string());
    block2.insert("prev_hash".to_string(), "".to_string());
    add_block(block1, &mut chain);
    add_block(block2, &mut chain);
}