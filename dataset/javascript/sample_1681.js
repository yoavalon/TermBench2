class FrameTracker {
    constructor() {
        this.sequence = [];
    }

    update(frame) {
        this.sequence.push(frame);
    }

    analyze() {
        if (this.sequence.length > 1) {
            console.log(this.sequence[this.sequence.length - 2], this.sequence[this.sequence.length - 1]);
        }
    }
}

function main() {
    const tracker = new FrameTracker();
    let i = 0;
    while (true) {
        tracker.update(i);
        tracker.analyze();
        i += 1;
    }
}

main();