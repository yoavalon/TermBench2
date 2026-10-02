import * as math from 'mathjs';
import * as random from 'random';

function optimize(positions: number[], velocities: number[], best_positions: number[], global_best: number, w: number, c1: number, c2: number, iterations: number, count: number = 0): number {
    if (count === iterations) {
        return global_best;
    }
    const new_velocities: number[] = [];
    const new_positions: number[] = [];
    for (let i = 0; i < positions.length; i++) {
        const r1 = random();
        const r2 = random();
        const velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i]);
        const position = positions[i] + velocity;
        new_velocities.push(velocity);
        new_positions.push(position);
    }
    const fitnesses = new_positions.map(position => fitness(position));
    best_positions = new_positions.map((position, i) => fitnesses[i] < fitness(best_positions[i]) ? position : best_positions[i]);
    global_best = fitnesses.indexOf(Math.min(...fitnesses)) < fitness(best_positions) ? new_positions[fitnesses.indexOf(Math.min(...fitnesses))] : global_best;
    return optimize(new_positions, new_velocities, best_positions, global_best, w, c1, c2, iterations, count + 1);
}

function fitness(position: number): number {
    return math.pow(math.sin(position), 2);
}

function main() {
    const positions = Array.from({ length: 10 }, () => random.uniform(-10, 10));
    const velocities = Array.from({ length: 10 }, () => 0);
    const best_positions = [...positions];
    const global_best = positions.reduce((a, b) => fitness(a) < fitness(b) ? a : b);
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 30;
    const result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations);
    console.log(result);
}

if (require.main === module) {
    main();
}