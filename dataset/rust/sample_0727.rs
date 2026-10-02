fn validate_block(block: &std::collections::HashMap<&str, &str>, prev_hash: &str) -> bool {
    if block["prev_hash"] == prev_hash && block["data"] == hash_data(block["data"]).to_string() {
        true
    } else {
        false
    }
}

fn hash_data(data: &str) -> i32 {
    let mut result = 0;
    for char in data.chars() {
        result = (result + char as i32 * 17) % 10007;
    }
    result
}

fn verify_chain(chain: Vec<std::collections::HashMap<&str, &str>>) -> bool {
    if chain.is_empty() {
        return true;
    }
    if chain.len() == 1 {
        return validate_block(&chain[0], "genesis");
    }
    validate_block(&chain[chain.len() - 1], chain[chain.len() - 2]["hash"]) && verify_chain(chain[..chain.len() - 1].to_vec())
}

fn main() {
    let blockchain = vec![
        [("hash", "genesis"), ("data", "initial")].iter().cloned().collect(),
        [("hash", "hash1"), ("data", "data1"), ("prev_hash", "genesis")].iter().cloned().collect(),
        [("hash", "hash2"), ("data", "data2"), ("prev_hash", "hash1")].iter().cloned().collect(),
    ];
    println!("{}", verify_chain(blockchain));
}