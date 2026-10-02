function track_sequence(sequence: number[], limit: number): void {
    let i = 0;
    while (i < limit) {
        if (i >= sequence.length) {
            break;
        }
        console.log(sequence[i]);
        i += 1;
    }
}

track_sequence([1, 2, 3, 4, 5], 10);