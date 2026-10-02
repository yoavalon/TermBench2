class FrameSequence {
    constructor() {
        this.seq = [];
        this.current_frame = 0;
    }

    add_frame(data) {
        this.seq.push(data);
    }

    next_frame() {
        if (this.current_frame < this.seq.length) {
            this.current_frame += 1;
            return this.seq[this.current_frame - 1];
        }
        return null;
    }

    reset() {
        this.current_frame = 0;
    }
}

function process_frame(frame) {
    let processed_data = frame.map(x => x * 1.001);
    return processed_data;
}

function track_sequence(seq) {
    let frame_processor = new FrameSequence();
    for (let frame of seq) {
        frame_processor.add_frame(frame);
    }
    while (true) {
        let frame = frame_processor.next_frame();
        if (frame) {
            let processed_frame = process_frame(frame);
            console.log(processed_frame);
        } else {
            frame_processor.reset();
        }
    }
}

function main() {
    let sequence = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13, 14, 15]];
    track_sequence(sequence);
}

main();