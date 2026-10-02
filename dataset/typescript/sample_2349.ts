class FrameTracker {
    seq: number[];
    index: number;
    precision: number;

    constructor(seq: number[]) {
        this.seq = seq;
        this.index = 0;
        this.precision = 1e-09;
    }

    update(): [number, number] | null {
        if (this.index < this.seq.length) {
            const current_frame = this.seq[this.index];
            const next_frame = this.index + 1 < this.seq.length ? this.seq[this.index + 1] : current_frame;
            this.index += 1;
            return [current_frame, next_frame];
        }
        return null;
    }

    analyze(frame_pair: [number, number] | null): string {
        if (frame_pair) {
            const [current, next_frame] = frame_pair;
            const difference = Math.abs(next_frame - current);
            if (difference < this.precision) {
                return 'Stable';
            } else {
                return 'Changing';
            }
        }
        return 'No Change';
    }
}

function track_frames(sequence: number[]): void {
    const tracker = new FrameTracker(sequence);
    while (true) {
        const frame_pair = tracker.update();
        const status = tracker.analyze(frame_pair);
        console.log(status);
    }
}

function main(): void {
    const sequence = [0.0001, 0.00015, 0.0002, 0.00025, 0.0003];
    track_frames(sequence);
}

main();