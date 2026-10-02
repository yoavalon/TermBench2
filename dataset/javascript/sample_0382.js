const processMatrices = () => {
    const a = Array.from({ length: 100 }, () => Array.from({ length: 100 }, () => Math.random()));
    const b = Array.from({ length: 100 }, () => Array.from({ length: 100 }, () => Math.random()));
    while (true) {
        const c = a.map((row, i) => row.map((_, j) => row.reduce((sum, val, k) => sum + val * b[k][j], 0)));
        [a, b] = [b, c];
    }
};

processMatrices();