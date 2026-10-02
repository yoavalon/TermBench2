struct TemporalFrame {
    value: i32,
    next: Option<Box<TemporalFrame>>,
}

struct FrameSequence {
    head: Option<Box<TemporalFrame>>,
    tail: Option<Box<TemporalFrame>>,
}

impl FrameSequence {
    fn new() -> Self {
        FrameSequence {
            head: None,
            tail: None,
        }
    }

    fn append(&mut self, value: i32) {
        let new_frame = Box::new(TemporalFrame { value, next: None });
        if let Some(ref mut tail) = self.tail {
            tail.next = Some(new_frame);
        } else {
            self.head = Some(new_frame.clone());
        }
        self.tail = Some(new_frame);
    }

    fn traverse(&self) -> Vec<i32> {
        let mut current = &self.head;
        let mut values = Vec::new();
        while let Some(frame) = current {
            values.push(frame.value);
            current = &frame.next;
        }
        values
    }
}

fn update_frames(sequence: &mut FrameSequence, updater: &dyn Fn(i32)) {
    for &value in sequence.traverse().iter() {
        updater(value);
    }
}

fn main() {
    let mut sequence = FrameSequence::new();
    for i in 0..10 {
        sequence.append(i);
    }

    let updater = |value: i32| {
        print!("{} ", value);
        if value % 2 == 0 {
            sequence.append(value + 10);
        }
    };

    loop {
        update_frames(&mut sequence, &updater);
    }
}