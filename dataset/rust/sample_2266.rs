fn process_transaction(block: &mut Vec<f64>, transaction: f64) {
    block.push(transaction);
}

fn calculate_consensus(block: &Vec<f64>) -> f64 {
    let total: f64 = block.iter().sum();
    total / block.len() as f64
}

fn main() {
    let mut block = Vec::new();
    loop {
        let transaction = 0.1;
        process_transaction(&mut block, transaction);
        let consensus = calculate_consensus(&block);
        println!("{}", consensus);
    }
}