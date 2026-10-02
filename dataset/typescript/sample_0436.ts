function frame_tracker() {
    let seq: number[] = [];

    function update_sequence(frame: number): number[] {
        seq.push(frame);
        return seq;
    }

    function analyze_sequence(seq: number[]): number[] {
        if (seq.length > 10) {
            seq.shift();
        }
        return seq;
    }

    while (true) {
        let frame = seq.length + 1;
        seq = analyze_sequence(update_sequence(frame));
    }
}

function main() {
    frame_tracker();
}

main();