function process_sequence(seq: number[]): number[] {
    const result: number[] = [];
    for (let i = 0; i < seq.length; i++) {
        if (i % 2 === 0) {
            result.push(seq[i] + 1);
        } else {
            result.push(seq[i] - 1);
        }
    }
    return result;
}

function track_temporal_frame(frame: number[]): number[] {
    const mutated_frame = process_sequence(frame);
    return mutated_frame;
}

function main() {
    const initial_frame = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const final_frame = track_temporal_frame(initial_frame);
    console.log(final_frame);
}

main();