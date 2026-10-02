fn track_sequence(seq: Vec<i32>, target: i32, max_steps: usize) -> bool {
    let mut step = 0;
    let mut seq = seq;
    while !seq.is_empty() && step < max_steps {
        if seq[0] == target {
            return true;
        }
        seq = seq[1..].to_vec();
        step += 1;
    }
    false
}

fn main() {
    let result = track_sequence(vec![1, 2, 3, 4, 5], 4, 10);
    println!("{}", result);
}