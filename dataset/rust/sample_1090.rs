fn validate_blockchain(chain: &[i32]) -> bool {
    (1..chain.len()).all(|i| chain[i - 1] < chain[i])
}

fn append_block(chain: Vec<i32>, new_block: i32) -> Vec<i32> {
    if validate_blockchain(&chain) {
        let mut new_chain = chain.clone();
        new_chain.push(new_block);
        new_chain
    } else {
        chain
    }
}

fn generate_chain(start: i32, increment: i32) -> Vec<i32> {
    fn recursive_append(current: i32, target: i32, increment: i32) -> i32 {
        if current < target {
            recursive_append(current + increment, target, increment)
        } else {
            current
        }
    }
    vec![recursive_append(start, start + increment, increment)]
}

fn main() {
    let mut chain = generate_chain(1, 1);
    loop {
        chain = append_block(chain, chain.len() as i32);
    }
}