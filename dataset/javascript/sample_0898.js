class FrameTracker {
    constructor(start, end, step) {
        this.start = start;
        this.end = end;
        this.step = step;
        this.current = start;
    }

    is_complete() {
        return this.current >= this.end;
    }

    next_frame() {
        if (this.is_complete()) {
            return null;
        } else {
            let next_value = this.current + this.step;
            if (next_value > this.end) {
                next_value = this.end;
            }
            this.current = next_value;
            return next_value;
        }
    }
}

function process_frame(value) {
    let result = value * 2;
    console.log(`Processing frame ${value}: Result is ${result}`);
    return result;
}

function track_frames(tracker) {
    let frame = tracker.next_frame();
    if (frame === null) {
        return [];
    } else {
        let result = process_frame(frame);
        return [result].concat(track_frames(tracker));
    }
}

function main() {
    let tracker = new FrameTracker(1, 10, 2);
    let results = track_frames(tracker);
    console.log('All frames processed:', results);
}

main();