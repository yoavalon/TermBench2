function track_sequence(frame_sequence: number[], boundary_condition: number): number {
    const sequence_length = frame_sequence.length;
    for (let idx = 0; idx < sequence_length; idx++) {
        if (frame_sequence[idx] === boundary_condition || idx === sequence_length - 1) {
            return idx;
        }
    }
    return -1;
}

const frame_sequence = [1, 2, 3, 4, 5];
const boundary_condition = 3;
const result = track_sequence(frame_sequence, boundary_condition);
console.log(result);