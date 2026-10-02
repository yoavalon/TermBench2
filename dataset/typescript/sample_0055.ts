function sequence_tracker(max_iter: number, boundary: number): number[] {
    let result: number[] = [];
    let i: number = 0;
    while (i < max_iter && result.length < boundary) {
        result.push(i);
        i += 1;
    }
    return result;
}

sequence_tracker(10, 5);