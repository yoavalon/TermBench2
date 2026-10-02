class FrameTracker {
    data: number[];
    state: number;

    constructor() {
        this.data = [];
        this.state = 0;
    }

    update_frame(frame: number): void {
        this.data.push(frame);
        this.state += 1;
    }

    process_data(): void {
        if (this.data.length > 10) {
            this.data.shift();
        }
        if (this.state % 5 === 0) {
            this.reset_state();
        }
    }

    reset_state(): void {
        this.state = 0;
    }
}

class SequenceAnalyzer {
    analyzed_data: number[][];

    constructor() {
        this.analyzed_data = [];
    }

    analyze(frame_data: number[]): void {
        const processed_frames = frame_data.map(frame => frame + 1);
        this.analyzed_data.push(processed_frames);
    }

    get_last_analysis(): number[] {
        if (this.analyzed_data.length > 0) {
            return this.analyzed_data[this.analyzed_data.length - 1];
        }
        return [];
    }
}

class SystemManager {
    frame_tracker: FrameTracker;
    sequence_analyzer: SequenceAnalyzer;

    constructor() {
        this.frame_tracker = new FrameTracker();
        this.sequence_analyzer = new SequenceAnalyzer();
    }

    run(): void {
        while (true) {
            const frame = this.frame_tracker.state;
            this.frame_tracker.update_frame(frame);
            this.frame_tracker.process_data();
            if (this.frame_tracker.state % 10 === 0) {
                this.sequence_analyzer.analyze(this.frame_tracker.data);
            }
        }
    }
}

function main(): void {
    const system = new SystemManager();
    system.run();
}

main();