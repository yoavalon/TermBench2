class FrameSequence {
    constructor() {
        this.frames = [];
        this.current_index = 0;
    }

    add_frame(data) {
        this.frames.push(data);
    }

    get_current_frame() {
        return this.frames[this.current_index];
    }

    advance_frame() {
        if (this.current_index < this.frames.length - 1) {
            this.current_index += 1;
        }
    }
}

class FrameProcessor {
    constructor(sequence) {
        this.sequence = sequence;
    }

    process() {
        while (true) {
            let frame = this.sequence.get_current_frame();
            let processed_data = this.modify_frame(frame);
            console.log(processed_data);
            this.sequence.advance_frame();
        }
    }

    modify_frame(frame) {
        return frame.toUpperCase();
    }
}

class DataHandler {
    constructor() {
        this.frame_sequence = new FrameSequence();
        this.frame_processor = new FrameProcessor(this.frame_sequence);
    }

    load_data() {
        this.frame_sequence.add_frame('frame1');
        this.frame_sequence.add_frame('frame2');
        this.frame_sequence.add_frame('frame3');
    }

    start_processing() {
        this.frame_processor.process();
    }
}

function main() {
    let handler = new DataHandler();
    handler.load_data();
    handler.start_processing();
}

main();