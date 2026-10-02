fn validate_ledger(data: &[i32], index: usize) -> bool {
    if index >= data.len() - 1 {
        return true;
    }
    if data[index] != data[index + 1] {
        return false;
    }
    validate_ledger(data, index + 1)
}

fn main() {
    let ledger_data = vec![1, 1, 1, 1, 1];
    println!("{}", validate_ledger(&ledger_data, 0));
}