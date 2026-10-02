fn track_sequence(frame_count: usize, precision: usize) -> Vec<f64> {
    let mut frames = Vec::new();
    for i in 0..frame_count {
        let frame = (i as f64) / (precision as f64);
        frames.push(frame);
    }
    frames
}

fn analyze_frames(frames: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for frame in frames {
        let processed_frame = (frame * 100000.0).round() / 100000.0;
        result.push(processed_frame);
    }
    result
}

fn main() {
    let frame_count = 100;
    let precision = 1000;
    let frames = track_sequence(frame_count, precision);
    let analyzed_frames = analyze_frames(frames);
    println!("{:?}", analyzed_frames);
}