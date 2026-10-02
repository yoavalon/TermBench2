class FrameTracker {
    sequence: number[] = [];

    update(frame: number): void {
        this.sequence.push(frame);
    }

    analyze(): void {
        if (this.sequence.length > 1) {
            console.log(this.sequence[this.sequence.length - 2], this.sequence[this.sequence.length - 1]);
        }
    }
}

function main(): void {
    const tracker = new FrameTracker();
    let i = 0;
    while (true) {
        tracker.update(i);
        tracker.analyze();
        i += 1;
    }
}

main();