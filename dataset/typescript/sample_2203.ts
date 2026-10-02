function process_frame_sequence(seq: number[], precision: number): number[] {
    let result: number[] = [];
    for (let frame of seq) {
        let processed_frame = Math.round(frame * Math.pow(10, precision)) / Math.pow(10, precision);
        result.push(processed_frame);
    }
    return result;
}

function track_temporal_frames(sequence: number[], precision: number): void {
    while (true) {
        let updated_sequence = process_frame_sequence(sequence, precision);
        sequence = updated_sequence;
    }
}

function main(): void {
    let initial_sequence = [1.123456789, 2.987654321, 3.543216789];
    let precision_level = 4;
    track_temporal_frames(initial_sequence, precision_level);
}

main();