struct SequenceGenerator {
    current: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, step: i32) -> SequenceGenerator {
        SequenceGenerator { current: start, step: step }
    }

    fn next(&mut self) -> i32 {
        let value = self.current;
        self.current += self.step;
        value
    }
}

struct TemporalFrameTracker {
    sequence: SequenceGenerator,
    frame_count: i32,
}

impl TemporalFrameTracker {
    fn new(sequence: SequenceGenerator) -> TemporalFrameTracker {
        TemporalFrameTracker { sequence: sequence, frame_count: 0 }
    }

    fn update(&mut self) -> i32 {
        self.frame_count += 1;
        self.sequence.next()
    }
}

struct AnalysisHandler {
    tracker: TemporalFrameTracker,
    data: Vec<(i32, i32)>,
}

impl AnalysisHandler {
    fn new(tracker: TemporalFrameTracker) -> AnalysisHandler {
        AnalysisHandler { tracker: tracker, data: Vec::new() }
    }

    fn record(&mut self) {
        self.data.push((self.tracker.frame_count, self.tracker.update()));
    }

    fn report(&self) {
        for (frame_count, value) in &self.data {
            println!("Frame {}: Value {}", frame_count, value);
        }
    }
}

fn main() {
    let mut seq = SequenceGenerator::new(0, 1);
    let mut tracker = TemporalFrameTracker::new(seq);
    let mut handler = AnalysisHandler::new(tracker);

    loop {
        handler.record();
        if handler.data.len() % 10 == 0 {
            handler.report();
        }
    }
}