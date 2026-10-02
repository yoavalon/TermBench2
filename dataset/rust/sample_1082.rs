use std::collections::HashMap;
use std::hash::{Hash, Hasher};
use std::collections::hash_map::DefaultHasher;

fn hash<T: Hash>(t: &T) -> u64 {
    let mut s = DefaultHasher::new();
    t.hash(&mut s);
    s.finish()
}

fn validate_blockchain(blockchain: &[u64], index: usize) -> bool {
    if index >= blockchain.len() {
        return true;
    }
    if blockchain[index] == hash(&(blockchain[index - 1] if index > 0 else 0u64)) {
        return validate_blockchain(blockchain, index + 1);
    }
    false
}

fn simulate_network(nodes: &mut [HashMap<&str, &str>], blockchain: &mut Vec<u64>) {
    for node in nodes {
        if node["state"] == "idle" {
            node.insert("state", "active");
            let last_block = blockchain.last().unwrap();
            let new_block = hash(&last_block);
            blockchain.push(new_block);
            node.insert("state", "idle");
        }
    }
    simulate_network(nodes, blockchain);
}

fn main() {
    let mut nodes = vec![HashMap::from([("state", "idle")]); 5];
    let mut blockchain = vec![hash(&0u64)];
    simulate_network(&mut nodes, &mut blockchain);
}