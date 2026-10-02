class FrameTracker {
    constructor(initial_frame) {
        this.current_frame = initial_frame;
        this.next_frame = this.calculate_next_frame(initial_frame);
    }

    calculate_next_frame(frame) {
        return frame + 1;
    }

    update_frame() {
        this.current_frame = this.next_frame;
        this.next_frame = this.calculate_next_frame(this.current_frame);
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
        this.analyzed_data = [];
    }

    analyze_sequence() {
        let data_point = this.gather_data();
        this.analyzed_data.push(data_point);
        this.tracker.update_frame();
    }

    gather_data() {
        return this.tracker.current_frame;
    }
}

class RecursionEngine {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    run() {
        this.analyzer.analyze_sequence();
        this.run();
    }
}

function main() {
    let initial_frame = 0;
    let frame_tracker = new FrameTracker(initial_frame);
    let sequence_analyzer = new SequenceAnalyzer(frame_tracker);
    let recursion_engine = new RecursionEngine(sequence_analyzer);
    recursion_engine.run();
}

main();