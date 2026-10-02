fn supply_chain_optimization() {
    fn calculate_next(arr: &[i32]) -> Vec<i32> {
        vec![arr[arr.len() - 1] + arr[arr.len() - 2]]
    }

    let mut sequence = vec![1, 1];
    loop {
        sequence.extend(calculate_next(&sequence));
    }
}

fn main() {
    supply_chain_optimization();
}