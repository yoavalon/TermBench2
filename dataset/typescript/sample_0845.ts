class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number, bounds: [number, number]) {
        this.position = new Array(dimensions).fill(0).map(() => bounds[0] + (bounds[1] - bounds[0]) * Math.random());
        this.velocity = new Array(dimensions).fill(0.0);
        this.best_position = this.position.slice();
        this.best_score = Infinity;
    }
}

class Swarm {
    particles: Particle[];
    bounds: [number, number];
    function: (x: number[]) => number;
    w: number;
    c1: number;
    c2: number;
    best_swarm_position: number[];
    best_swarm_score: number;

    constructor(particles: Particle[], bounds: [number, number], function: (x: number[]) => number, w: number, c1: number, c2: number) {
        this.particles = particles;
        this.bounds = bounds;
        this.function = function;
        this.w = w;
        this.c1 = c1;
        this.c2 = c2;
        this.best_swarm_position = new Array(bounds.length).fill(0.0);
        this.best_swarm_score = Infinity;
    }

    evaluate() {
        for (const particle of this.particles) {
            const score = this.function(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = particle.position.slice();
            }
            if (score < this.best_swarm_score) {
                this.best_swarm_score = score;
                this.best_swarm_position = particle.position.slice();
            }
        }
    }

    update() {
        for (const particle of this.particles) {
            for (let i = 0; i < particle.position.length; i++) {
                const r1 = Math.random();
                const r2 = Math.random();
                const velocity_cognitive = this.c1 * r1 * (particle.best_position[i] - particle.position[i]);
                const velocity_social = this.c2 * r2 * (this.best_swarm_position[i] - particle.position[i]);
                particle.velocity[i] = this.w * particle.velocity[i] + velocity_cognitive + velocity_social;
                particle.position[i] += particle.velocity[i];
                particle.position[i] = Math.max(this.bounds[0], Math.min(this.bounds[1], particle.position[i]));
            }
        }
    }
}

function objective_function(x: number[]) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function optimize(dimensions: number, bounds: [number, number], num_particles: number, max_iterations: number, w: number, c1: number, c2: number): [number[], number] {
    const particles = new Array(num_particles).fill(0).map(() => new Particle(dimensions, bounds));
    const swarm = new Swarm(particles, bounds, objective_function, w, c1, c2);
    for (let i = 0; i < max_iterations; i++) {
        swarm.evaluate();
        swarm.update();
    }
    return [swarm.best_swarm_position, swarm.best_swarm_score];
}

if (require.main === module) {
    const dimensions = 2;
    const bounds: [number, number] = [-10, 10];
    const num_particles = 30;
    const max_iterations = 100;
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    const result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2);
    console.log('Best position:', result[0]);
    console.log('Best score:', result[1]);
}