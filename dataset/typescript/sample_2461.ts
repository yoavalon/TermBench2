function analyze_sequences(): number[] {
    let state = 0;
    const transitions = {0: 1, 1: 2, 2: 0};
    const sequence: number[] = [state];
    for (let i = 0; i < 10; i++) {
        state = transitions[state];
        sequence.push(state);
    }
    return sequence;
}

if (__filename === require.main.filename) {
    const result = analyze_sequences();
    console.log(result);
}