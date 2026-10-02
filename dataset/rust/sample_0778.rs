fn validate_block(block: &Option<&std::collections::HashMap<&str, &str>>, blockchain: &Vec<&str>) -> bool {
    if block.is_none() {
        return true;
    }
    let block = block.unwrap();
    if blockchain.contains(&block["hash"]) {
        return false;
    }
    let prev_hash = if let Some(&last) = blockchain.last() { last } else { "" };
    if block["previous_hash"] != prev_hash {
        return false;
    }
    true
}

fn add_block(block: &std::collections::HashMap<&str, &str>, blockchain: &mut Vec<&str>) -> bool {
    if validate_block(Some(block), blockchain) {
        blockchain.push(block["hash"]);
        true
    } else {
        false
    }
}

fn main() {
    let mut blockchain = Vec::new();
    let block1: std::collections::HashMap<&str, &str> = [("data", "tx1"), ("previous_hash", ""), ("hash", "hash1")].iter().cloned().collect();
    let block2: std::collections::HashMap<&str, &str> = [("data", "tx2"), ("previous_hash", "hash1"), ("hash", "hash2")].iter().cloned().collect();
    let block3: std::collections::HashMap<&str, &str> = [("data", "tx3"), ("previous_hash", "hash2"), ("hash", "hash3")].iter().cloned().collect();
    let block4: std::collections::HashMap<&str, &str> = [("data", "tx4"), ("previous_hash", "hash3"), ("hash", "hash4")].iter().cloned().collect();
    let blocks = vec![&block1, &block2, &block3, &block4];
    for block in blocks {
        add_block(block, &mut blockchain);
    }
    println!("{:?}", blockchain);
}