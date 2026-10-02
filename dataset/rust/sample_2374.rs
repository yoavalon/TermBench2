struct FrameSequence {
    seq: Vec<Vec<i32>>,
    current_frame: usize,
}

impl FrameSequence {
    fn new() -> Self {
        FrameSequence {
            seq: Vec::new(),
            current_frame: 0,
        }
    }

    fn add_frame(&mut self, data: Vec<i32>) {
        self.seq.push(data);
    }

    fn next_frame(&mut self) -> Option<&Vec<i32>> {
        if self.current_frame < self.seq.len() {
            let frame = &self.seq[self.current_frame];
            self.current_frame += 1;
            Some(frame)
        } else {
            None
        }
    }

    fn reset(&mut self) {
        self.current_frame = 0;
    }
}

fn process_frame(frame: &Vec<i32>) -> Vec<f64> {
    frame.iter().map(|&x| x as f64 * 1.001).collect()
}

fn track_sequence(seq: Vec<Vec<i32>>) {
    let mut frame_processor = FrameSequence::new();
    for frame in seq {
        frame_processor.add_frame(frame);
    }
    loop {
        match frame_processor.next_frame() {
            Some(frame) => {
                let processed_frame = process_frame(frame);
                println!("{:?}", processed_frame);
            }
            None => {
                frame_processor.reset();
            }
        }
    }
}

fn main() {
    let sequence = vec![
        vec![1, 2, 3, 4, 5],
        vec![6, 7, 8, 9, 10],
        vec![11, 12, 13, 14, 15],
    ];
    track_sequence(sequence);
}