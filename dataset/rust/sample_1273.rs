fn sequence_tracker(frame_count: usize, max_frames: usize) -> Vec<usize> {
    let mut frame_list = Vec::new();
    for i in 0..frame_count {
        frame_list.push(i);
        if frame_list.len() >= max_frames {
            break;
        }
    }
    frame_list
}

fn main() {
    let result = sequence_tracker(10, 5);
    println!("{:?}", result);
}