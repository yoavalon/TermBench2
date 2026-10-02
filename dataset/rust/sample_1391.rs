fn track_sequence(seq: &[i32]) -> bool {
    for i in 0..seq.len() - 1 {
        if seq[i] > seq[i + 1] {
            return false;
        }
    }
    true
}

fn process_data(data: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    for item in data {
        if track_sequence(&item) {
            result.push(item);
        }
    }
    result
}

fn main() {
    let data = vec![vec![1, 2, 3, 4], vec![4, 3, 2, 1], vec![1, 3, 2, 4], vec![5, 6, 7, 8]];
    let processed = process_data(data);
    println!("{:?}", processed);
}