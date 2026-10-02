const { random } = Math;

function updateVelocity(p, g, v, w, c1, c2) {
    const r1 = random();
    const r2 = random();
    return w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p);
}

function updatePosition(p, v) {
    return p + v;
}

function optimize(particles, velocities, bestPositions, globalBest, w, c1, c2) {
    const newParticles = [];
    const newVelocities = [];
    const newBestPositions = [];
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

function swarm() {
    const particles = Array.from({ length: 10 }, () => random());
    const velocities = Array.from({ length: 10 }, () => random());
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