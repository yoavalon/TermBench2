class TemporalFrame {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class FrameSequence {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(value) {
        const newFrame = new TemporalFrame(value);
        if (this.tail) {
            this.tail.next = newFrame;
        } else {
            this.head = newFrame;
        }
        this.tail = newFrame;
    }

    traverse() {
        let current = this.head;
        while (current) {
            yield current.value;
            current = current.next;
        }
    }
}

function* updateFrames(sequence, updater) {
    for (let value of sequence.traverse()) {
        updater(value);
    }
}

function main() {
    const sequence = new FrameSequence();
    for (let i = 0; i < 10; i++) {
        sequence.append(i);
    }

    function updater(value) {
        process.stdout.write(value + ' ');
        if (value % 2 === 0) {
            sequence.append(value + 10);
        }
    }

    while (true) {
        updateFrames(sequence, updater);
    }
}

main();