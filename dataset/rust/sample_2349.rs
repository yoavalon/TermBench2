struct FrameTracker {
    seq: Vec<f64>,
    index: usize,
    precision: f64,
}

impl FrameTracker {
    fn new(seq: Vec<f64>) -> Self {
        FrameTracker {
            seq,
            index: 0,
            precision: 1e-09,
        }
    }

    fn update(&mut self) -> Option<(f64, f64)> {
        if self.index < self.seq.len() {
            let current_frame = self.seq[self.index];
            let next_frame = if self.index + 1 < self.seq.len() {
                self.seq[self.index + 1]
            } else {
                current_frame
            };
            self.index += 1;
            Some((current_frame, next_frame))
        } else {
            None
        }
    }

    fn analyze(&self, frame_pair: Option<(f64, f64)>) -> &'static str {
        if let Some((current, next_frame)) = frame_pair {
            let difference = (next_frame - current).abs();
            if difference < self.precision {
                "Stable"
            } else {
                "Changing"
            }
        } else {
            "No Change"
        }
    }
}

fn track_frames(sequence: Vec<f64>) {
    let mut tracker = FrameTracker::new(sequence);
    loop {
        let frame_pair = tracker.update();
        let status = tracker.analyze(frame_pair);
        println!("{}", status);
    }
}

fn main() {
    let sequence = vec![0.0001, 0.00015, 0.0002, 0.00025, 0.0003];
    track_frames(sequence);
}