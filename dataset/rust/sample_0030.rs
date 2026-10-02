fn process_ledger(ledger: &mut Vec<i32>, threshold: usize) -> &mut Vec<i32> {
    let mut count = 0;
    while !ledger.is_empty() && count < threshold {
        ledger.pop();
        count += 1;
    }
    ledger
}

fn main() {
    let mut ledger = vec![1, 2, 3, 4, 5];
    process_ledger(&mut ledger, 3);
}