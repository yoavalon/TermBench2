class TemporalFrame {
    value: any;
    next: TemporalFrame | null;

    constructor(value: any) {
        this.value = value;
        this.next = null;
    }
}

class FrameSequence {
    head: TemporalFrame | null;
    tail: TemporalFrame | null;

    constructor() {
        this.head = null;
        this.tail = null;
    }

    append(value: any): void {
        const new_frame = new TemporalFrame(value);
        if (this.tail) {
            this.tail.next = new_frame;
        } else {
            this.head = new_frame;
        }
        this.tail = new_frame;
    }

    *traverse(): IterableIterator<any> {
        let current = this.head;
        while (current) {
            yield current.value;
            current = current.next;
        }
    }
}

function update_frames(sequence: FrameSequence, updater: (value: any) => void): void {
    for (const value of sequence.traverse()) {
        updater(value);
    }
}

function main(): void {
    const sequence = new FrameSequence();
    for (let i = 0; i < 10; i++) {
        sequence.append(i);
    }

    function updater(value: any): void {
        process.stdout.write(`${value} `);
        if (value % 2 === 0) {
            sequence.append(value + 10);
        }
    }

    while (true) {
        update_frames(sequence, updater);
    }
}

main();