import * as random from 'random';

class Swarm {
    size: number;
    dimensions: number;
    search_space: [number, number];
    particles: Particle[];

    constructor(size: number, dimensions: number, search_space: [number, number]) {
        this.size = size;
        this.dimensions = dimensions;
        this.search_space = search_space;
        this.particles = Array.from({ length: size }, () => new Particle(dimensions, search_space));
    }

    update() {
        for (const particle of this.particles) {
            particle.update_velocity();
            particle.update_position();
        }
    }
}

class Particle {
    dimensions: number;
    search_space: [number, number];
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dimensions: number, search_space: [number, number]) {
        this.dimensions = dimensions;
        this.search_space = search_space;
        this.position = Array.from({ length: dimensions }, () => random.uniform(search_space[0], search_space[1]));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity() {
        const w = 0.7;
        const c1 = 1.5;
        const c2 = 1.5;
        for (let i = 0; i < this.dimensions; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (this.best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.dimensions; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(this.search_space[0], Math.min(this.search_space[1], this.position[i]));
        }
    }
}

function fitness_function(position: number[]): number {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function optimize(swarm: Swarm, max_iterations: number) {
    for (let iteration = 0; iteration < max_iterations; iteration++) {
        for (const particle of swarm.particles) {
            const current_fitness = fitness_function(particle.position);
            if (current_fitness < particle.best_fitness) {
                particle.best_fitness = current_fitness;
                particle.best_position = [...particle.position];
            }
        }
        swarm.update();
    }
}

function main() {
    const size = 30;
    const dimensions = 2;
    const search_space: [number, number] = [-10, 10];
    const max_iterations = 100;
    const swarm = new Swarm(size, dimensions, search_space);
    optimize(swarm, max_iterations);
}

main();