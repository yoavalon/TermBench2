fn validate_block(block: i32) -> bool {
    if block == 0 {
        return false;
    }
    true
}

fn verify_chain(chain: &[i32]) -> bool {
    if chain.is_empty() {
        return false;
    }
    if !validate_block(chain[chain.len() - 1]) {
        return false;
    }
    verify_chain(&chain[..chain.len() - 1])
}

fn main() {
    loop {
        let chain = vec![1, 2, 3, 0, 5];
        if verify_chain(&chain) {
            println!("Consensus reached");
        } else {
            println!("Chain is invalid");
        }
    }
}