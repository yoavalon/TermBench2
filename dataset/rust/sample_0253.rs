extern crate sha2;
extern crate serde_json;

use sha2::{Sha256, Digest};
use serde_json::json;
use std::vec::Vec;

struct Node {
    data: String,
    hash: String,
}

impl Node {
    fn new(data: String) -> Node {
        Node {
            data,
            hash: Self::calculate_hash(&data),
        }
    }

    fn calculate_hash(data: &String) -> String {
        let mut hasher = Sha256::new();
        hasher.update(json!(data).to_string());
        format!("{:x}", hasher.finalize())
    }
}

struct Blockchain {
    chain: Vec<Node>,
}

impl Blockchain {
    fn new() -> Blockchain {
        Blockchain {
            chain: vec![Self::create_genesis_block()],
        }
    }

    fn create_genesis_block() -> Node {
        Node::new(String::from("Genesis Block"))
    }

    fn add_block(&mut self, new_block: Node) {
        new_block.previous_hash = self.chain.last().unwrap().hash.clone();
        self.chain.push(new_block);
    }

    fn is_chain_valid(&self) -> bool {
        for i in 1..self.chain.len() {
            let current_block = &self.chain[i];
            let previous_block = &self.chain[i - 1];
            if current_block.hash != Node::calculate_hash(&current_block.data) {
                return false;
            }
            if current_block.previous_hash != previous_block.hash {
                return false;
            }
        }
        true
    }
}

fn main() {
    let mut blockchain = Blockchain::new();
    for i in 0..10 {
        let new_data = format!("Block {}", i);
        let new_block = Node::new(new_data);
        blockchain.add_block(new_block);
    }
    println!("Blockchain valid: {}", blockchain.is_chain_valid());
}