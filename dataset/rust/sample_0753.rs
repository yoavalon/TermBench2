use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

fn validate_blockchain(blockchain: &[u8], index: usize) -> bool {
    if index >= blockchain.len() {
        return true;
    }
    let prev_block = if index > 0 { &blockchain[index - 1] } else { b"" };
    let prev_hash = hash(prev_block);
    if blockchain[index] != prev_hash {
        return false;
    }
    validate_blockchain(blockchain, index + 1)
}

fn append_block(blockchain: &mut Vec<u8>, data: &[u8]) {
    let last_block = if !blockchain.is_empty() { &blockchain[blockchain.len() - 1] } else { b"" };
    let new_block = hash(last_block) ^ hash(data);
    blockchain.push(new_block);
}

fn hash<T: Hash>(t: &T) -> u8 {
    let mut s = DefaultHasher::new();
    t.hash(&mut s);
    s.finish() as u8
}

fn main() {
    let mut blockchain = vec![b'g', b'e', b'n', b'e', b's', b'i', b's'];
    for _ in 0..5 {
        append_block(&mut blockchain, b"transaction");
    }
    println!("{}", validate_blockchain(&blockchain, 0));
}