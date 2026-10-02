function consensus_mechanism() {
    let a = 1, b = 0;
    for (let i = 0; i < 10; i++) {
        [a, b] = [b, a + b];
    }
    return a;
}
consensus_mechanism();