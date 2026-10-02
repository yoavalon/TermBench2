const math = require('mathjs');

function optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations, count = 0) {
    if (count == iterations) {
        return global_best;
    }
    let new_velocities = [];
    let new_positions = [];
    for (let i = 0; i < positions.length; i++) {
        let r1 = Math.random();
        let r2 = Math.random();
        let velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i]);
        let position = positions[i] + velocity;
        new_velocities.push(velocity);
        new_positions.push(position);
    }
    let fitnesses = new_positions.map(position => fitness(position));
    best_positions = new_positions.map((position, i) => fitnesses[i] < fitness(best_positions[i]) ? position : best_positions[i]);
    global_best = fitnesses.some(fitness => fitness < fitness(global_best)) ? new_positions.reduce((a, b) => fitness(a) < fitness(b) ? a : b) : global_best;
    return optimize(new_positions, new_velocities, best_positions, global_best, w, c1, c2, iterations, count + 1);
}

function fitness(position) {
    return math.pow(math.sin(position), 2);
}

function main() {
    let positions = Array.from({ length: 10 }, () => Math.random() * 20 - 10);
    let velocities = Array.from({ length: 10 }, () => 0);
    let best_positions = [...positions];
    let global_best = positions.reduce((a, b) => fitness(a) < fitness(b) ? a : b);
    let w = 0.7, c1 = 1.5, c2 = 1.5;
    let iterations = 30;
    let result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations);
    console.log(result);
}

main();