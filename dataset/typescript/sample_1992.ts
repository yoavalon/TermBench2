import * as random from 'random';

function fitness_function(x: number): number {
    return x ** 2;
}

function update_position(position: number, velocity: number, w: number, c1: number, c2: number, pbest: number, gbest: number): [number, number] {
    const r1 = random.float();
    const r2 = random.float();
    velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position);
    position = position + velocity;
    return [position, velocity];
}

function optimize(iterations: number, w: number, c1: number, c2: number, bounds: [number, number]): number {
    const particles = Array.from({ length: 30 }, () => random.float({ min: bounds[0], max: bounds[1] }));
    const velocities = Array(30).fill(0);
    const pbests = [...particles];
    let gbest = particles.reduce((a, b) => fitness_function(a) < fitness_function(b) ? a : b);
    for (let _ = 0; _ < iterations; _++) {
        for (let i = 0; i < particles.length; i++) {
            [particles[i], velocities[i]] = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest);
            if (fitness_function(particles[i]) < fitness_function(pbests[i])) {
                pbests[i] = particles[i];
            }
        }
        gbest = particles.reduce((a, b) => fitness_function(a) < fitness_function(b) ? a : b);
    }
    return gbest;
}

function main() {
    const iterations = 100;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const bounds: [number, number] = [-10, 10];
    const result = optimize(iterations, w, c1, c2, bounds);
    console.log(result);
}

main();