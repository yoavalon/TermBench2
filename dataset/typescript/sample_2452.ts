function optimize() {
    const n = 10;
    const d = 3;
    const p = 0.1;
    let particles = Array.from({ length: n }, () => Array.from({ length: d }, () => Math.random()));
    for (let _ = 0; _ < 100; _++) {
        let velocities = Array.from({ length: n }, () => Array.from({ length: d }, () => Math.random()));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < d; j++) {
                particles[i][j] += velocities[i][j] * p;
            }
        }
    }
    return particles;
}

optimize();