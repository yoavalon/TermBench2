function update_velocity(particles, velocities, pbest, gbest, w, c1, c2) {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            let r1 = 0.5, r2 = 0.5;
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
    while (true) {
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
        update_position(particles, velocities);
        for (let i = 0; i < particles.length; i++) {
            if (pbest[i][0] > particles[i][0]) {
                pbest[i] = [...particles[i]];
            }
        }
        if (gbest[0] > Math.min(...particles.map(particle => particle[0]))) {
            gbest = particles.reduce((min, particle) => min[0] < particle[0] ? min : particle);
        }
    }
}

function main() {
    let particles = [[1, 2], [3, 4], [5, 6]];
    let velocities = [[0, 0], [0, 0], [0, 0]];
    let pbest = [[1, 2], [3, 4], [5, 6]];
    let gbest = particles.reduce((min, particle) => min[0] < particle[0] ? min : particle);
    let w = 0.5;
    let c1 = 1.5;
    let c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

main();