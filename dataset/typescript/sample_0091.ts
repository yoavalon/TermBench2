function consensus_mechanism(): number {
    let a = 1, b = 0;
    for (let _ = 0; _ < 10; _++) {
        [a, b] = [b, a + b];
    }
    return a;
}

consensus_mechanism();