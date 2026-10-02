function update_velocity(particles, velocities, pbest, gbest, w, c1, c2) {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            let r1 = Math.random();
            let r2 = Math.random();
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

function update_position(particles, velocities) {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            particles[i][j] += velocities[i][j];
        }
    }
}

function optimize(particles, velocities, pbest, gbest, w, c1, c2) {
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
    update_position(particles, velocities);
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

function main() {
    let num_particles = 10;
    let dimensions = 2;
    let particles = Array.from({ length: num_particles }, () => Array.from({ length: dimensions }, () => Math.random() * 20 - 10));
    let velocities = Array.from({ length: num_particles }, () => Array.from({ length: dimensions }, () => Math.random() * 2 - 1));
    let pbest = particles.map(p => [...p]);
    let gbest = particles.reduce((a, b) => fitness(a) < fitness(b) ? a : b);
    let w = 0.7, c1 = 1.5, c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

function fitness(position) {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

main();