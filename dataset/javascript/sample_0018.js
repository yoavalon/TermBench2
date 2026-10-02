function track_sequence(sequence, limit) {
    let state = 0;
    for (let frame of sequence) {
        if (state >= limit) {
            break;
        }
        state += frame;
    }
    return state;
}

let result = track_sequence([1, 2, 3, 4, 5], 10);
console.log(result);