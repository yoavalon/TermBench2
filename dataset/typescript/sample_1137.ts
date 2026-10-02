class FrameTracker {
    current_frame: number;
    next_frame: number;

    constructor(initial_frame: number) {
        this.current_frame = initial_frame;
        this.next_frame = this.calculate_next_frame(initial_frame);
    }

    calculate_next_frame(frame: number): number {
        return frame + 1;
    }

    update_frame(): void {
        this.current_frame = this.next_frame;
        this.next_frame = this.calculate_next_frame(this.current_frame);
    }
}

class SequenceAnalyzer {
    tracker: FrameTracker;
    analyzed_data: number[];

    constructor(tracker: FrameTracker) {
        this.tracker = tracker;
        this.analyzed_data = [];
    }

    analyze_sequence(): void {
        const data_point = this.gather_data();
        this.analyzed_data.push(data_point);
        this.tracker.update_frame();
    }

    gather_data(): number {
        return this.tracker.current_frame;
    }
}

class RecursionEngine {
    analyzer: SequenceAnalyzer;

    constructor(analyzer: SequenceAnalyzer) {
        this.analyzer = analyzer;
    }

    run(): void {
        this.analyzer.analyze_sequence();
        this.run();
    }
}

function main(): void {
    const initial_frame = 0;
    const frame_tracker = new FrameTracker(initial_frame);
    const sequence_analyzer = new SequenceAnalyzer(frame_tracker);
    const recursion_engine = new RecursionEngine(sequence_analyzer);
    recursion_engine.run();
}

main();