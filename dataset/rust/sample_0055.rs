fn sequence_tracker(max_iter: usize, boundary: usize) -> Vec<usize> {
    let mut result = Vec::new();
    let mut i = 0;
    while i < max_iter && result.len() < boundary {
        result.push(i);
        i += 1;
    }
    result
}

fn main() {
    sequence_tracker(10, 5);
}