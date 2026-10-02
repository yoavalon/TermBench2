class Particle {
    position: number[];
    velocity: number[];
    pbest: number[];
    pbest_value: number;

    constructor(dim: number) {
        this.position = new Array(dim).fill(0.0);
        this.velocity = new Array(dim).fill(0.0);
        this.pbest = new Array(dim).fill(0.0);
        this.pbest_value = Infinity;
    }

    update_velocity(gbest: number[], w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = 0.5, r2 = 0.5;
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.pbest[i] - this.position[i]) + c2 * r2 * (gbest[i] - this.position[i]);
        }
    }

    update_position(bounds: [number, number][]) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(bounds[i][1], this.position[i]));
        }
    }

    update_pbest(value: number) {
        if (value < this.pbest_value) {
            this.pbest = [...this.position];
            this.pbest_value = value;
        }
    }
}

class Swarm {
    particles: Particle[];
    gbest: number[];
    gbest_value: number;
    bounds: [number, number][];

    constructor(num_particles: number, dim: number, bounds: [number, number][]) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dim));
        this.gbest = new Array(dim).fill(0.0);
        this.gbest_value = Infinity;
        this.bounds = bounds;
    }

    update_gbest() {
        for (const particle of this.particles) {
            if (particle.pbest_value < this.gbest_value) {
                this.gbest = [...particle.pbest];
                this.gbest_value = particle.pbest_value;
            }
        }
    }

    iterate() {
        for (const particle of this.particles) {
            particle.update_velocity(this.gbest);
            particle.update_position(this.bounds);
            particle.update_pbest(objective_function(particle.position));
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function optimize(num_particles: number, dim: number, max_iterations: number, bounds: [number, number][]): [number[], number] {
    const swarm = new Swarm(num_particles, dim, bounds);
    for (let i = 0; i < max_iterations; i++) {
        swarm.iterate();
        swarm.update_gbest();
    }
    return [swarm.gbest, swarm.gbest_value];
}

function main() {
    const num_particles = 30;
    const dim = 2;
    const max_iterations = 100;
    const bounds: [number, number][] = Array(dim).fill([-10, 10]);
    const [best_position, best_value] = optimize(num_particles, dim, max_iterations, bounds);
    console.log('Best position:', best_position);
    console.log('Best value:', best_value);
}

main();