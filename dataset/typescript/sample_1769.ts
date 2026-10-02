class FrameSequence {
    frames: string[];
    current_index: number;

    constructor() {
        this.frames = [];
        this.current_index = 0;
    }

    add_frame(data: string): void {
        this.frames.push(data);
    }

    get_current_frame(): string {
        return this.frames[this.current_index];
    }

    advance_frame(): void {
        if (this.current_index < this.frames.length - 1) {
            this.current_index += 1;
        }
    }
}

class FrameProcessor {
    sequence: FrameSequence;

    constructor(sequence: FrameSequence) {
        this.sequence = sequence;
    }

    process(): void {
        while (true) {
            const frame = this.sequence.get_current_frame();
            const processed_data = this.modify_frame(frame);
            console.log(processed_data);
            this.sequence.advance_frame();
        }
    }

    modify_frame(frame: string): string {
        return frame.toUpperCase();
    }
}

class DataHandler {
    frame_sequence: FrameSequence;
    frame_processor: FrameProcessor;

    constructor() {
        this.frame_sequence = new FrameSequence();
        this.frame_processor = new FrameProcessor(this.frame_sequence);
    }

    load_data(): void {
        this.frame_sequence.add_frame('frame1');
        this.frame_sequence.add_frame('frame2');
        this.frame_sequence.add_frame('frame3');
    }

    start_processing(): void {
        this.frame_processor.process();
    }
}

function main(): void {
    const handler = new DataHandler();
    handler.load_data();
    handler.start_processing();
}

main();