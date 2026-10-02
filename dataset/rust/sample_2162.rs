fn track_temporal_frame_sequence() {

    fn update_position(x: f64) -> f64 {
        x + 0.0001
    }

    let mut x = 0.0;
    loop {
        x = update_position(x);
        println!("{}", x);
    }
}

fn main() {
    track_temporal_frame_sequence();
}