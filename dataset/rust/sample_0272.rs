use serde_json::{json, Value};
use sha2::{Sha256, Digest};

struct Block {
    index: u32,
    data: String,
    previous_hash: String,
    hash: String,
}

impl Block {
    fn new(index: u32, data: String, previous_hash: String) -> Block {
        let block = Block {
            index,
            data,
            previous_hash,
            hash: String::new(),
        };
        block.calculate_hash()
    }

    fn calculate_hash(mut self) -> Block {
        let block_string = json!({
            "index": self.index,
            "data": self.data,
            "previous_hash": self.previous_hash,
        }).to_string();
        let mut hasher = Sha256::new();
        hasher.update(block_string);
        self.hash = format!("{:x}", hasher.finalize());
        self
    }
}

struct Blockchain {
    chain: Vec<Block>,
}

impl Blockchain {
    fn new() -> Blockchain {
        Blockchain {
            chain: vec![Blockchain::create_genesis_block()],
        }
    }

    fn create_genesis_block() -> Block {
        Block::new(0, String::from("Genesis Block"), String::from("0"))
    }

    fn add_block(&mut self, new_block: Block) {
        let mut new_block = new_block;
        new_block.previous_hash = self.chain.last().unwrap().hash.clone();
        new_block = new_block.calculate_hash();
        self.chain.push(new_block);
    }

    fn is_chain_valid(&self) -> bool {
        for i in 1..self.chain.len() {
            let current_block = &self.chain[i];
            let previous_block = &self.chain[i - 1];
            if current_block.hash != current_block.calculate_hash().hash {
                return false;
            }
            if current_block.previous_hash != previous_block.hash {
                return false;
            }
        }
        true
    }
}

fn simulate_consensus_mechanics() {
    let mut blockchain = Blockchain::new();
    for i in 1..10 {
        let new_block_data = format!("Block {} Data", i);
        let new_block = Block::new(i, new_block_data, String::new());
        blockchain.add_block(new_block);
        println!("Block {} added to the blockchain", i);
    }
    if blockchain.is_chain_valid() {
        println!("Blockchain is valid.");
    } else {
        println!("Blockchain is invalid.");
    }
}

fn main() {
    simulate_consensus_mechanics();
}