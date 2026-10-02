function analyze_sequences() {
    let state = 0;
    const transitions = {0: 1, 1: 2, 2: 0};
    let sequence = [state];
    for (let i = 0; i < 10; i++) {
        state = transitions[state];
        sequence.push(state);
    }
    return sequence;
}

if (typeof require !== 'undefined' && require.main === module) {
    const result = analyze_sequences();
    console.log(result);
}