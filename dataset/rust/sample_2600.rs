fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 1..=n {
        sequence.push(i * (i + 1) / 2);
    }
    sequence
}

fn optimize_inventory(seq: &Vec<usize>, target: usize) -> (Option<usize>, Option<usize>) {
    for (i, &value) in seq.iter().enumerate() {
        if value >= target {
            return (Some(i), Some(value));
        }
    }
    (None, None)
}

fn main() {
    let n = 10;
    let target = 20;
    let seq = generate_sequence(n);
    let (index, value) = optimize_inventory(&seq, target);
    if let Some(index) = index {
        println!("Optimal index: {}, Value: {}", index, value.unwrap());
    } else {
        println!("Target not met.");
    }
}