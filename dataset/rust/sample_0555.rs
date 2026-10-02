struct SequenceTracker {
    sequence: Vec<i32>,
    index: usize,
    history: Vec<i32>,
}

impl SequenceTracker {
    fn new(sequence: Vec<i32>) -> Self {
        SequenceTracker {
            sequence,
            index: 0,
            history: Vec::new(),
        }
    }

    fn update(&mut self) {
        if self.index < self.sequence.len() {
            self.history.push(self.sequence[self.index]);
            self.index += 1;
        } else {
            self.index = 0;
        }
    }

    fn get_history(&self) -> &Vec<i32> {
        &self.history
    }
}

struct BoundaryConditions {
    lower: i32,
    upper: i32,
}

impl BoundaryConditions {
    fn new(lower: i32, upper: i32) -> Self {
        BoundaryConditions { lower, upper }
    }

    fn is_within_boundaries(&self, value: i32) -> bool {
        self.lower <= value && value <= self.upper
    }
}

struct TemporalFrameSequence {
    tracker: SequenceTracker,
    boundary_conditions: BoundaryConditions,
}

impl TemporalFrameSequence {
    fn new(tracker: SequenceTracker, boundary_conditions: BoundaryConditions) -> Self {
        TemporalFrameSequence {
            tracker,
            boundary_conditions,
        }
    }

    fn process(&mut self) {
        loop {
            self.tracker.update();
            if self.boundary_conditions.is_within_boundaries(*self.tracker.get_history().last().unwrap()) {
                println!("{}", self.tracker.get_history().last().unwrap());
            } else {
                println!("Out of boundaries");
            }
        }
    }
}

fn main() {
    let sequence = vec![10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    let tracker = SequenceTracker::new(sequence);
    let boundary_conditions = BoundaryConditions::new(30, 70);
    let mut temporal_frame_sequence = TemporalFrameSequence::new(tracker, boundary_conditions);
    temporal_frame_sequence.process();
}