struct SequenceTracker {
    value: i32,
    increment: i32,
    max_iterations: i32,
    current_iteration: i32,
}

impl SequenceTracker {
    fn new(initial_value: i32, increment: i32, max_iterations: i32) -> SequenceTracker {
        SequenceTracker {
            value: initial_value,
            increment: increment,
            max_iterations: max_iterations,
            current_iteration: 0,
        }
    }

    fn next(&mut self) -> Option<i32> {
        if self.current_iteration < self.max_iterations {
            self.value += self.increment;
            self.current_iteration += 1;
            Some(self.value)
        } else {
            None
        }
    }
}

struct SequenceObserver {
    completed: bool,
}

impl SequenceObserver {
    fn new() -> SequenceObserver {
        SequenceObserver {
            completed: false,
        }
    }

    fn on_next(&self, value: i32) {
        println!("Current value: {}", value);
    }

    fn complete(&mut self) {
        println!("Sequence tracking completed.");
        self.completed = true;
    }
}

fn monitor_sequence(tracker: &mut SequenceTracker, observer: &mut SequenceObserver) {
    loop {
        match tracker.next() {
            Some(result) => observer.on_next(result),
            None => {
                observer.complete();
                break;
            }
        }
    }
}

fn main() {
    let mut tracker = SequenceTracker::new(0, 1, 10);
    let mut observer = SequenceObserver::new();
    monitor_sequence(&mut tracker, &mut observer);
}