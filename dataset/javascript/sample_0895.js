class FrameTracker {
    constructor(sequence, index = 0) {
        this.sequence = sequence;
        this.index = index;
    }

    next_frame() {
        if (this.index < this.sequence.length - 1) {
            this.index += 1;
        }
        return this.sequence[this.index];
    }

    previous_frame() {
        if (this.index > 0) {
            this.index -= 1;
        }
        return this.sequence[this.index];
    }

    current_frame() {
        return this.sequence[this.index];
    }
}

function process_frame(frame) {
    return frame + 1;
}

function track_sequence(tracker, direction, count) {
    if (count > 0) {
        let new_frame;
        if (direction === 'forward') {
            new_frame = tracker.next_frame();
        } else {
            new_frame = tracker.previous_frame();
        }
        let processed_frame = process_frame(new_frame);
        console.log(processed_frame);
        track_sequence(tracker, direction, count - 1);
    }
}

function main() {
    let sequence = [10, 20, 30, 40, 50];
    let tracker = new FrameTracker(sequence);
    track_sequence(tracker, 'forward', 3);
    track_sequence(tracker, 'backward', 2);
}

main();