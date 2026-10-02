import * as random from 'random';

function updateVelocity(p: number, g: number, v: number, w: number, c1: number, c2: number): number {
    const r1 = random.random();
    const r2 = random.random();
    return w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p);
}

function updatePosition(p: number, v: number): number {
    return p + v;
}

function optimize(particles: number[], velocities: number[], bestPositions: number[], globalBest: number, w: number, c1: number, c2: number): [number[], number[], number[]] {
    const newParticles: number[] = [];
    const newVelocities: number[] = [];
    const newBestPositions: number[] = [];
    for (let i = 0; i < particles.length; i++) {
        const v = updateVelocity(particles[i], globalBest, velocities[i], w, c1, c2);
        const p = updatePosition(particles[i], v);
        newParticles.push(p);
        newVelocities.push(v);
        if (p < bestPositions[i]) {
            newBestPositions.push(p);
        } else {
            newBestPositions.push(bestPositions[i]);
        }
    }
    return [newParticles, newVelocities, newBestPositions];
}

function swarm(): void {
    const particles = Array.from({ length: 10 }, () => random.random());
    const velocities = Array.from({ length: 10 }, () => random.random());
    const bestPositions = [...particles];
    let globalBest = Math.min(...particles);
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    while (true) {
        [particles, velocities, bestPositions] = optimize(particles, velocities, bestPositions, globalBest, w, c1, c2);
        globalBest = Math.min(...bestPositions);
    }
}

swarm();