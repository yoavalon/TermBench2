function consensus(state, threshold, depth) {
    if (depth === 0 || state.reduce((a, b) => a + b, 0) >= threshold) {
        return state;
    } else {
        return consensus(state.map(x => x < threshold ? x + 1 : x), threshold, depth - 1);
    }
}
consensus([0, 0, 0], 5, 3);