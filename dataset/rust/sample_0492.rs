fn validate_transaction(tx: i32) -> bool {
    true
}

fn process_block(block: Vec<i32>) -> bool {
    for tx in block {
        if !validate_transaction(tx) {
            return false;
        }
    }
    true
}

fn add_block_to_chain(chain: Vec<Vec<i32>>, block: Vec<i32>) -> Vec<Vec<i32>> {
    if process_block(block.clone()) {
        let mut new_chain = chain.clone();
        new_chain.push(block);
        new_chain
    } else {
        chain
    }
}

fn main() {
    let mut chain = Vec::new();
    loop {
        let new_block = vec![1, 2, 3];
        chain = add_block_to_chain(chain, new_block);
    }
}