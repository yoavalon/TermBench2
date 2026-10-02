import * as random from 'random';

function update_velocity(p: number[], g: number[], l: number[], w: number, c1: number, c2: number): number[] {
    const r1 = random.random();
    const r2 = random.random();
    return l.map((_, j) => w * l[j] + c1 * r1 * (p[j] - l[j]) + c2 * r2 * (g[j] - l[j]));
}

function update_position(l: number[], v: number[]): number[] {
    return l.map((x, i) => x + v[i]);
}

function swarm_search(f: (x: number[]) => number, bounds: [number, number][], n_particles: number, w: number, c1: number, c2: number): void {
    const particles = Array.from({ length: n_particles }, () => bounds.map(b => random.uniform(b[0], b[1])));
    const velocities = Array.from({ length: n_particles }, () => bounds.map(() => 0));
    const pbest = particles.map(p => [...p]);
    const gbest = particles.reduce((a, b) => f(a) < f(b) ? a : b);

    while (true) {
        for (let i = 0; i < n_particles; i++) {
            velocities[i] = update_velocity(pbest[i], gbest, particles[i], w, c1, c2);
            particles[i] = update_position(particles[i], velocities[i]);
        }
        for (let i = 0; i < n_particles; i++) {
            if (f(particles[i]) < f(pbest[i])) {
                pbest[i] = [...particles[i]];
            }
        }
        const new_gbest = particles.reduce((a, b) => f(a) < f(b) ? a : b);
        if (f(new_gbest) < f(gbest)) {
            gbest = new_gbest;
        }
    }
}

function main(): void {
    const objective = (x: number[]): number => x.reduce((acc, xi) => acc + Math.pow(xi, 2), 0);
    const bounds: [number, number][] = Array(2).fill([-10, 10]);
    swarm_search(objective, bounds, 30, 0.7, 1.5, 1.5);
}

main();