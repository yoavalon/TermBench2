class FrameSequence {
    constructor(frames) {
        this.frames = frames;
        this.index = 0;
    }

    get_current_frame() {
        if (this.index < this.frames.length) {
            return this.frames[this.index];
        } else {
            return null;
        }
    }

    next_frame() {
        if (this.index < this.frames.length - 1) {
            this.index += 1;
        }
        return this.get_current_frame();
    }
}

function track_sequence(sequence, tracker) {
    let current_frame = sequence.get_current_frame();
    if (current_frame !== null) {
        console.log(`Tracking frame: ${current_frame}`);
        tracker(current_frame);
        track_sequence(sequence, tracker);
    }
}

function analyze_frame(frame) {
    console.log(`Analyzing frame: ${frame}`);
    if (frame % 2 === 0) {
        console.log('Frame is even.');
    } else {
        console.log('Frame is odd.');
    }
}

function main() {
    let frames = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let sequence = new FrameSequence(frames);
    track_sequence(sequence, analyze_frame);
}

main();