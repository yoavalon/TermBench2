fn validate_block(block: &Option<&std::collections::HashMap<&str, &str>>) -> bool {
    if let Some(block) = block {
        if block.len() != 3 {
            return false;
        }
        for key in ["hash", "data", "prev_hash"] {
            if !block.contains_key(key) {
                return false;
            }
        }
        true
    } else {
        false
    }
}

fn verify_chain(chain: &Vec<Option<std::collections::HashMap<&str, &str>>>, index: usize) -> bool {
    if index >= chain.len() || chain[index].is_none() {
        return true;
    }
    if !validate_block(&chain[index]) {
        return false;
    }
    if index > 0 {
        let current_block = chain[index].as_ref().unwrap();
        let prev_block = chain[index - 1].as_ref().unwrap();
        if current_block["prev_hash"] != prev_block["hash"] {
            return false;
        }
    }
    verify_chain(chain, index + 1)
}

fn main() {
    let blockchain = vec![
        Some(std::collections::HashMap::from([
            ("hash", "A"),
            ("data", "Genesis"),
            ("prev_hash", "None"),
        ])),
        Some(std::collections::HashMap::from([
            ("hash", "B"),
            ("data", "Block1"),
            ("prev_hash", "A"),
        ])),
        Some(std::collections::HashMap::from([
            ("hash", "C"),
            ("data", "Block2"),
            ("prev_hash", "B"),
        ])),
    ];
    if verify_chain(&blockchain, 0) {
        println!("Chain is valid.");
    } else {
        println!("Chain is invalid.");
    }
}