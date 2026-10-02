const random = require('random');

function fitness_function(x) {
    return x ** 2;
}

function update_position(position, velocity, w, c1, c2, pbest, gbest) {
    const r1 = random.float(0, 1);
    const r2 = random.float(0, 1);
    velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position);
    position = position + velocity;
    return [position, velocity];
}

function optimize(iterations, w, c1, c2, bounds) {
    const particles = Array.from({ length: 30 }, () => random.float(bounds[0], bounds[1]));
    const velocities = Array.from({ length: 30 }, () => 0);
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
    const bounds = [-10, 10];
    const result = optimize(iterations, w, c1, c2, bounds);
    console.log(result);
}

main();