class FrameTracker {
    constructor() {
        this.frames = [];
        this.current_frame = 0;
    }

    add_frame(data) {
        this.frames.push(data);
        this.current_frame = this.frames.length - 1;
    }

    get_current_frame() {
        return this.frames[this.current_frame];
    }

    advance_frame() {
        if (this.current_frame < this.frames.length - 1) {
            this.current_frame += 1;
        }
        return this.get_current_frame();
    }

    rewind_frame() {
        if (this.current_frame > 0) {
            this.current_frame -= 1;
        }
        return this.get_current_frame();
    }
}

class DataMutator {
    constructor(tracker) {
        this.tracker = tracker;
    }

    mutate(data) {
        data['timestamp'] = new Date().toISOString();
        return data;
    }
}

function main() {
    const tracker = new FrameTracker();
    const mutator = new DataMutator(tracker);
    for (let i = 0; i < 10; i++) {
        const frame_data = {'id': i, 'value': i * 10};
        const mutated_data = mutator.mutate(frame_data);
        tracker.add_frame(mutated_data);
    }
    while (true) {
        const current_frame = tracker.get_current_frame();
        console.log('Current Frame:', current_frame);
        if (tracker.advance_frame() === current_frame) {
            tracker.rewind_frame();
        }
    }
}

main();