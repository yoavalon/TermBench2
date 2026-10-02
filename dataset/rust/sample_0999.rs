fn track_sequence(frame: u64, next_frame: u64) -> u64 {
    let result = track_sequence(next_frame, frame + next_frame);
    result
}

fn main() {
    track_sequence(0, 1);
}