import java.util.*;

class SequenceTracker {
    int current;
    int step;

    SequenceTracker(int start, int step) {
        this.current = start;
        this.step = step;
    }

    void advance() {
        this.current += this.step;
    }

    int get_value() {
        return this.current;
    }
}

class SequenceAnalyzer {
    SequenceTracker tracker;

    SequenceAnalyzer(SequenceTracker tracker) {
        this.tracker = tracker;
    }

    void analyze() {
        int value = this.tracker.get_value();
        if (value > 1000) {
            this.tracker.step = -this.tracker.step;
        } else if (value < -1000) {
            this.tracker.step = -this.tracker.step;
        }
    }
}

class SequenceController {
    SequenceTracker tracker;
    SequenceAnalyzer analyzer;

    SequenceController(SequenceTracker tracker, SequenceAnalyzer analyzer) {
        this.tracker = tracker;
        this.analyzer = analyzer;
    }

    void run() {
        while (true) {
            this.analyzer.analyze();
            this.tracker.advance();
        }
    }
}

public class sample_1774 {
    public static void main(String[] args) {
        SequenceTracker tracker = new SequenceTracker(0, 10);
        SequenceAnalyzer analyzer = new SequenceAnalyzer(tracker);
        SequenceController controller = new SequenceController(tracker, analyzer);
        controller.run();
    }
}