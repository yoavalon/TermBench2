fn update_sequence(sequence: &Vec<i32>, step: i32) -> Vec<i32> {
    let mut new_sequence = Vec::new();
    for &item in sequence {
        new_sequence.push(item + step);
    }
    new_sequence
}

fn check_boundary(sequence: &Vec<i32>, limit: i32) -> bool {
    for &item in sequence {
        if item >= limit {
            return true;
        }
    }
    false
}

fn main() {
    let mut seq = vec![0, 1, 2];
    let step = 1;
    let limit = 10;
    while !check_boundary(&seq, limit) {
        seq = update_sequence(&seq, step);
    }
    println!("Boundary reached: {:?}", seq);
}