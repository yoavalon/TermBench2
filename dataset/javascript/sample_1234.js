function track_sequence(seq, target, max_steps) {
    let step = 0;
    while (seq.length > 0 && step < max_steps) {
        if (seq[0] === target) {
            return true;
        }
        seq = seq.slice(1);
        step += 1;
    }
    return false;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = track_sequence([1, 2, 3, 4, 5], 4, 10);
    console.log(result);
}