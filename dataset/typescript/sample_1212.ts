function data_mutations(): number {
    let x = 1.0;
    const decay = 0.9;
    const epsilon = 0.001;
    while (x > epsilon) {
        x *= decay;
    }
    return x;
}

data_mutations();