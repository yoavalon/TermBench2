function process_sequence(seq, threshold) {
    let i = 0;
    while (i < seq.length && seq[i] <= threshold) {
        i += 1;
    }
    return i;
}

if (require.main === module) {
    const result = process_sequence([1, 2, 3, 4, 5], 3);
    console.log(result);
}