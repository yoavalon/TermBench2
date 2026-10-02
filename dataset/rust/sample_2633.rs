struct SequenceGenerator {
    current: i32,
    end: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32, step: i32) -> Self {
        SequenceGenerator { current: start, end, step }
    }

    fn generate(&mut self) -> Vec<i32> {
        let mut sequence = Vec::new();
        while self.current <= self.end {
            sequence.push(self.current);
            self.current += self.step;
        }
        sequence
    }
}

struct FrameTracker {
    sequence: Vec<i32>,
    index: usize,
}

impl FrameTracker {
    fn new(sequence: Vec<i32>) -> Self {
        FrameTracker { sequence, index: 0 }
    }

    fn next_frame(&mut self) -> Option<i32> {
        if self.index < self.sequence.len() {
            let value = self.sequence[self.index];
            self.index += 1;
            Some(value)
        } else {
            None
        }
    }
}

struct TemporalAnalysis {
    tracker: FrameTracker,
}

impl TemporalAnalysis {
    fn new(tracker: FrameTracker) -> Self {
        TemporalAnalysis { tracker }
    }

    fn analyze(&mut self) -> Vec<i32> {
        let mut result = Vec::new();
        while let Some(frame) = self.tracker.next_frame() {
            result.push(frame);
        }
        result
    }
}

fn main() {
    let start = 1;
    let end = 100;
    let step = 5;
    let mut generator = SequenceGenerator::new(start, end, step);
    let sequence = generator.generate();
    let mut tracker = FrameTracker::new(sequence);
    let mut analysis = TemporalAnalysis::new(tracker);
    let result = analysis.analyze();
    println!("{:?}", result);
}