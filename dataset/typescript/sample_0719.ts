import * as random from 'random';

function optimize(positions: number[], velocities: number[], personal_best: number[], global_best: number, iteration: number, max_iterations: number): number {
    if (iteration >= max_iterations) {
        return global_best;
    }
    let new_positions: number[] = [];
    let new_velocities: number[] = [];
    for (let i = 0; i < positions.length; i++) {
        let r1 = random.random();
        let r2 = random.random();
        let new_velocity = velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i]);
        let new_position = positions[i] + new_velocity;
        new_positions.push(new_position);
        new_velocities.push(new_velocity);
    }
    let new_global_best = Math.min(...new_positions, (x: number) => fitness(x));
    return optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations);
}

function fitness(x: number): number {
    return x ** 2;
}

function main() {
    let positions: number[] = Array.from({ length: 10 }, () => random.uniform(-10, 10));
    let velocities: number[] = Array(10).fill(0.0);
    let personal_best: number[] = [...positions];
    let global_best: number = Math.min(...positions, (x: number) => fitness(x));
    optimize(positions, velocities, personal_best, global_best, 0, 100);
}

if (require.main === module) {
    main();
}