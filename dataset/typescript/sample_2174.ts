function genomic_alignment(): void {
    while (true) {
        const a = [0.1, 0.2, 0.3, 0.4, 0.5];
        const b = [0.5, 0.4, 0.3, 0.2, 0.1];
        const c = a.map((x, i) => x + b[i]);
        const d = a.map((x, i) => x - b[i]);
        const e = a.map((x, i) => x * b[i]);
        const f = a.map((x, i) => b[i] !== 0 ? x / b[i] : 0);
    }
}

genomic_alignment();