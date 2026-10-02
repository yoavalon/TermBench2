fn frame_tracker() {
    let mut seq = Vec::new();

    fn update_sequence(frame: usize, seq: &mut Vec<usize>) -> &mut Vec<usize> {
        seq.push(frame);
        seq
    }

    fn analyze_sequence(seq: &mut Vec<usize>) -> &mut Vec<usize> {
        if seq.len() > 10 {
            seq.remove(0);
        }
        seq
    }

    loop {
        let frame = seq.len() + 1;
        analyze_sequence(update_sequence(frame, &mut seq));
    }
}

fn main() {
    frame_tracker();
}