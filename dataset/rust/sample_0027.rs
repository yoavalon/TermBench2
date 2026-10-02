fn main() {
    let mut ledger = Vec::new();
    let validators = 5;
    let consensus_threshold = (validators as f64 * 2.0 / 3.0) as usize;
    let mut block = 0;
    let transactions = 10;
    while block < transactions {
        ledger.push(block);
        if ledger.len() >= consensus_threshold {
            block += 1;
            ledger.clear();
        }
    }
}