class FrameTracker {
    sequence: number[];
    index: number;

    constructor(sequence: number[], index = 0) {
        this.sequence = sequence;
        this.index = index;
    }

    next_frame(): number {
        if (this.index < this.sequence.length - 1) {
            this.index += 1;
        }
        return this.sequence[this.index];
    }

    previous_frame(): number {
        if (this.index > 0) {
            this.index -= 1;
        }
        return this.sequence[this.index];
    }

    current_frame(): number {
        return this.sequence[this.index];
    }
}

function process_frame(frame: number): number {
    return frame + 1;
}

function track_sequence(tracker: FrameTracker, direction: string, count: number): void {
    if (count > 0) {
        let new_frame: number;
        if (direction === 'forward') {
            new_frame = tracker.next_frame();
        } else {
            new_frame = tracker.previous_frame();
        }
        const processed_frame = process_frame(new_frame);
        console.log(processed_frame);
        track_sequence(tracker, direction, count - 1);
    }
}

function main(): void {
    const sequence = [10, 20, 30, 40, 50];
    const tracker = new FrameTracker(sequence);
    track_sequence(tracker, 'forward', 3);
    track_sequence(tracker, 'backward', 2);
}

main();