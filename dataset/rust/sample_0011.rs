fn track_sequences(frame_count: i32, max_frames: i32) -> Vec<i32> {
    let mut frame_list = Vec::new();
    while frame_list.len() < max_frames as usize {
        frame_list.push(frame_count);
        frame_count += 1;
    }
    frame_list
}

fn main() {
    let result = track_sequences(0, 10);
    println!("{:?}", result);
}