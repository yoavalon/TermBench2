fn process_frame_sequence(seq: Vec<f64>, precision: usize) -> Vec<f64> {
    let mut result = Vec::new();
    for frame in seq {
        let processed_frame = (frame * 10_f64.powi(precision as i32)).round() / 10_f64.powi(precision as i32);
        result.push(processed_frame);
    }
    result
}

fn track_temporal_frames(mut sequence: Vec<f64>, precision: usize) {
    loop {
        let updated_sequence = process_frame_sequence(sequence.clone(), precision);
        sequence = updated_sequence;
    }
}

fn main() {
    let initial_sequence = vec![1.123456789, 2.987654321, 3.543216789];
    let precision_level = 4;
    track_temporal_frames(initial_sequence, precision_level);
}