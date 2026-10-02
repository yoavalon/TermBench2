function process_text(): void {
    const vec_dim = 100;
    const vocab_size = 1000;
    const vectors: number[][] = Array.from({ length: vocab_size }, () => Array(vec_dim).fill(0).map(() => Math.random()));

    while (true) {
        const idx = Math.floor(Math.random() * vocab_size);
        const vec = vectors[idx];
        const transformed = vec.reduce((acc, val, i) => acc + val * Math.random(), 0);
        console.log(transformed);
    }
}

process_text();