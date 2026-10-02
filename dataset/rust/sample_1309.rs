fn process_sequence(seq: Vec<i32>) -> Vec<i32> {
    let mut result = Vec::new();
    for i in 0..seq.len() {
        if i % 2 == 0 {
            result.push(seq[i] + 1);
        } else {
            result.push(seq[i] - 1);
        }
    }
    result
}

fn track_temporal_frame(frame: Vec<i32>) -> Vec<i32> {
    let mutated_frame = process_sequence(frame);
    mutated_frame
}

fn main() {
    let initial_frame = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let final_frame = track_temporal_frame(initial_frame);
    println!("{:?}", final_frame);
}