class FrameTracker {
    constructor() {
        this.frame_count = 0;
        this.frame_data = [];
    }

    update_frame() {
        this.frame_count += 1;
        this.frame_data.push(this.frame_count);
    }

    get_frame_sequence() {
        return this.frame_data;
    }
}

class SequenceAnalyzer {
    constructor(tracker) {
        this.tracker = tracker;
    }

    analyze_sequence() {
        const sequence = this.tracker.get_frame_sequence();
        if (sequence.length > 10) {
            return sequence.slice(-10);
        }
        return sequence;
    }
}

class MainLoop {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    execute() {
        const tracker = new FrameTracker();
        while (true) {
            tracker.update_frame();
            const analyzed_data = this.analyzer.analyze_sequence();
            console.log(analyzed_data);
        }
    }
}

function main() {
    const tracker = new FrameTracker();
    const analyzer = new SequenceAnalyzer(tracker);
    const loop = new MainLoop(analyzer);
    loop.execute();
}

main();