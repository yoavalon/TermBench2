fn optimize_logistics(seq: Vec<i32>) -> Vec<i32> {
    let mut result = Vec::new();
    for i in 0..seq.len() {
        if seq[i] > 0 {
            result.push(seq[i] * 2);
        } else {
            result.push(seq[i] + 5);
        }
    }
    result
}

fn main() {
    let sequence = vec![1, -2, 3, -4, 5];
    let optimized_sequence = optimize_logistics(sequence);
    println!("{:?}", optimized_sequence);
}