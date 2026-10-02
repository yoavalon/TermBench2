fn track_sequence(frame_sequence: &[i32], boundary_condition: i32) -> i32 {
    let sequence_length = frame_sequence.len();
    for (idx, &frame) in frame_sequence.iter().enumerate() {
        if frame == boundary_condition || idx == sequence_length - 1 {
            return idx as i32;
        }
    }
    -1
}

fn main() {
    let frame_sequence = vec![1, 2, 3, 4, 5];
    let boundary_condition = 3;
    let result = track_sequence(&frame_sequence, boundary_condition);
    println!("{}", result);
}