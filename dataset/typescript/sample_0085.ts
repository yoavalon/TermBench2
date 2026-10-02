function optimize(iterations: number, particles: number, dimensions: number): number[] {
    let velocity: number[][] = Array.from({ length: particles }, () => Array(dimensions).fill(0));
    let position: number[][] = Array.from({ length: particles }, () => Array(dimensions).fill(0));
    let best_position: number[][] = Array.from({ length: particles }, () => Array(dimensions).fill(0));
    let global_best: number[] = Array(dimensions).fill(0);

    for (let _ = 0; _ < iterations; _++) {
        for (let i = 0; i < particles; i++) {
            for (let j = 0; j < dimensions; j++) {
                velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j]);
                position[i][j] += velocity[i][j];
            }
        }
    }
    return global_best;
}

optimize(100, 20, 3);