use std::collections::HashMap;
use std::hash::{Hash, Hasher};

fn process_block(block: &HashMap<String, Vec<i32>>) -> u64 {
    let mut result = 0;
    for transaction in block.get("transactions").unwrap() {
        result += transaction.hash();
    }
    result
}

fn verify_consensus(chain: Vec<HashMap<String, HashMap<String, Vec<i32>>>>) -> impl Iterator<Item = Vec<HashMap<String, HashMap<String, Vec<i32>>>>> {
    std::iter::repeat(chain).map(move |chain| {
        for block in &chain {
            let block_hash = process_block(block);
            if *block.get("hash").unwrap() != block_hash {
                let mut mutable_block = block.clone();
                mutable_block.insert("hash".to_string(), block_hash.to_string().parse().unwrap());
            }
        }
        chain
    })
}

fn main() {
    let chain = vec![
        HashMap::from([
            ("transactions".to_string(), vec![1, 2, 3]),
            ("hash".to_string(), 0.to_string()),
        ]),
        HashMap::from([
            ("transactions".to_string(), vec![4, 5]),
            ("hash".to_string(), 0.to_string()),
        ]),
    ];
    for updated_chain in verify_consensus(chain) {
        println!("{:?}", updated_chain);
    }
}