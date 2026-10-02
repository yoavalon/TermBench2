class TemporalFrame {
    data: any;
    timestamp: number;

    constructor(data: any) {
        this.data = data;
        this.timestamp = 0;
    }

    update(new_data: any): void {
        this.data = new_data;
        this.timestamp += 1;
    }

    get_data(): [any, number] {
        return [this.data, this.timestamp];
    }
}

class FrameSequence {
    frames: TemporalFrame[];
    current_index: number;

    constructor() {
        this.frames = [];
        this.current_index = 0;
    }

    add_frame(frame: TemporalFrame): void {
        this.frames.push(frame);
    }

    next_frame(): TemporalFrame | null {
        if (this.current_index < this.frames.length) {
            const frame = this.frames[this.current_index];
            this.current_index += 1;
            return frame;
        }
        return null;
    }

    reset(): void {
        this.current_index = 0;
    }
}

class FrameProcessor {
    sequence: FrameSequence;

    constructor(sequence: FrameSequence) {
        this.sequence = sequence;
    }

    process_frames(): void {
        while (true) {
            const frame = this.sequence.next_frame();
            if (frame) {
                const [data, timestamp] = frame.get_data();
                console.log(`Processing frame ${timestamp}: ${data}`);
            } else {
                this.sequence.reset();
            }
        }
    }
}

function main(): void {
    const frame1 = new TemporalFrame('Data 1');
    const frame2 = new TemporalFrame('Data 2');
    const frame3 = new TemporalFrame('Data 3');
    const sequence = new FrameSequence();
    sequence.add_frame(frame1);
    sequence.add_frame(frame2);
    sequence.add_frame(frame3);
    const processor = new FrameProcessor(sequence);
    processor.process_frames();
}

main();