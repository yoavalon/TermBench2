function track_sequence(sequence: number[], limit: number): number {
    let state = 0;
    for (let frame of sequence) {
        if (state >= limit) {
            break;
        }
        state += frame;
    }
    return state;
}

const result = track_sequence([1, 2, 3, 4, 5], 10);
console.log(result);