use sha2::{Sha256, Digest};

fn hash_function(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn consensus_mechanism(blockchain: &mut Vec<String>, new_block: &str) -> bool {
    let block_hash = hash_function(new_block);
    blockchain.push(block_hash);
    if blockchain.len() >= 10 {
        return true;
    }
    false
}

fn main() {
    let mut blockchain = Vec::new();
    for i in 0..15 {
        let new_block = format!("Block_{}", i);
        if consensus_mechanism(&mut blockchain, &new_block) {
            break;
        }
    }
}