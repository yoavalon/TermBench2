function update_velocity(particles: number[][], velocities: number[][], pbest: number[][], gbest: number[], w: number, c1: number, c2: number): void {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            let r1 = 0.5, r2 = 0.5;
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

function update_position(particles: number[][], velocities: number[][]): void {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            particles[i][j] += velocities[i][j];
        }
    }
}

function optimize(particles: number[][], velocities: number[][], pbest: number[][], gbest: number[], w: number, c1: number, c2: number): void {
    while (true) {
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
        update_position(particles, velocities);
        for (let i = 0; i < particles.length; i++) {
            if (pbest[i][0] > particles[i][0]) {
                pbest[i] = particles[i].slice();
            }
        }
        if (gbest[0] > Math.min(...particles.map(particle => particle[0]))) {
            gbest = particles.reduce((a, b) => a[0] < b[0] ? a : b, particles[0]);
        }
    }
}

function main(): void {
    let particles: number[][] = [[1, 2], [3, 4], [5, 6]];
    let velocities: number[][] = [[0, 0], [0, 0], [0, 0]];
    let pbest: number[][] = [[1, 2], [3, 4], [5, 6]];
    let gbest: number[] = particles.reduce((a, b) => a[0] < b[0] ? a : b, particles[0]);
    let w: number = 0.5;
    let c1: number = 1.5;
    let c2: number = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

main();