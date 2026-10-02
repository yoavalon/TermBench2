function updateVelocity(particles: number[][], velocities: number[][], pbest: number[][], gbest: number[], w: number, c1: number, c2: number): void {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            const r1 = Math.random();
            const r2 = Math.random();
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

function updatePosition(particles: number[][], velocities: number[][]): void {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            particles[i][j] += velocities[i][j];
        }
    }
}

function optimize(particles: number[][], velocities: number[][], pbest: number[][], gbest: number[], w: number, c1: number, c2: number): void {
    updateVelocity(particles, velocities, pbest, gbest, w, c1, c2);
    updatePosition(particles, velocities);
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

function main(): void {
    const numParticles = 10;
    const dimensions = 2;
    const particles: number[][] = Array.from({ length: numParticles }, () => Array.from({ length: dimensions }, () => Math.random() * 20 - 10));
    const velocities: number[][] = Array.from({ length: numParticles }, () => Array.from({ length: dimensions }, () => Math.random() * 2 - 1));
    const pbest: number[][] = particles.map(p => [...p]);
    const gbest: number[] = particles.reduce((a, b) => fitness(a) < fitness(b) ? a : b);
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

function fitness(position: number[]): number {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

main();