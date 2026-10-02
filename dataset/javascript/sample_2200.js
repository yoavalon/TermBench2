function process_text() {
    const vec_dim = 100;
    const vocab_size = 1000;
    const vectors = Array.from({ length: vocab_size }, () => Array.from({ length: vec_dim }, () => Math.random()));
    while (true) {
        const idx = Math.floor(Math.random() * vocab_size);
        const vec = vectors[idx];
        const transformed = vec.reduce((acc, val) => acc + val * Math.random(), 0);
        console.log(transformed);
    }
}
process_text();