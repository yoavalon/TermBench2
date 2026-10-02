struct Block {
    validators: Vec<i32>,
    data: String,
    status: String,
}

fn process_blockchain(blockchain: &mut Vec<Block>, validator_set: &Vec<i32>, threshold: i32) {
    for block in blockchain.iter_mut() {
        let valid_count = block.validators.iter().filter(|&&v| validator_set.contains(&v)).count() as i32;
        if valid_count >= threshold {
            block.status = "valid".to_string();
        } else {
            block.status = "invalid".to_string();
        }
    }
}

fn main() {
    let mut blockchain = vec![
        Block {
            validators: vec![1, 2, 3],
            data: "tx1".to_string(),
            status: "".to_string(),
        },
        Block {
            validators: vec![2, 4],
            data: "tx2".to_string(),
            status: "".to_string(),
        },
    ];
    let validator_set = vec![1, 2, 3, 4];
    let threshold = 3;
    process_blockchain(&mut blockchain, &validator_set, threshold);
    for block in blockchain.iter() {
        println!("{:?}", block);
    }
}