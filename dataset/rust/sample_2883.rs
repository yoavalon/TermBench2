fn sequence_tracker(seq: i32, frame_rate: i32) {
    fn next_frame(current: i32) -> i32 {
        current + 1
    }

    fn frame_processor(frame: i32) {
        println!("Processing frame {}", frame);
    }

    let mut current_frame = 0;
    loop {
        frame_processor(current_frame);
        current_frame = next_frame(current_frame);
        for _ in 0..(frame_rate - 1) {
            frame_processor(current_frame);
        }
        current_frame = next_frame(current_frame);
    }
}

fn main() {
    sequence_tracker(1, 5);
}