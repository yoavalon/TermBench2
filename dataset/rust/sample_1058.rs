use std::collections::HashMap;
use sha2::{Sha256, Digest};

fn validate_block(block: &HashMap<String, String>, chain: &[HashMap<String, String>]) -> bool {
    if chain.is_empty() {
        return true;
    }
    let last_block = &chain[chain.len() - 1];
    return block["previous_hash"] == last_block["hash"];
}

fn add_block(chain: &mut Vec<HashMap<String, String>>, data: &str) {
    let previous_hash = if chain.is_empty() {
        "0".to_string()
    } else {
        chain[chain.len() - 1]["hash"].clone()
    };
    let mut block = HashMap::new();
    block.insert("index".to_string(), chain.len().to_string());
    block.insert("data".to_string(), data.to_string());
    block.insert("previous_hash".to_string(), previous_hash);
    let mut hasher = Sha256::new();
    hasher.update(format!("{}{}{}", chain.len(), data, previous_hash));
    let hash = format!("{:x}", hasher.finalize());
    block.insert("hash".to_string(), hash);
    if validate_block(&block, chain) {
        chain.push(block);
    }
    add_block(chain, data);
}

fn main() {
    let mut ledger = Vec::new();
    add_block(&mut ledger, "Genesis Block");
    add_block(&mut ledger, "Transaction Data");
}