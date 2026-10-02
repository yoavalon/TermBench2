class Swarm {
    size: number;
    dimensions: number;
    bounds: [number, number];
    particles: Particle[];
    gbest: Particle | null;

    constructor(size: number, dimensions: number, bounds: [number, number]) {
        this.size = size;
        this.dimensions = dimensions;
        this.bounds = bounds;
        this.particles = Array.from({ length: size }, () => new Particle(dimensions, bounds));
        this.gbest = null;
    }

    update_gbest() {
        for (const particle of this.particles) {
            if (this.gbest === null || particle.fitness < this.gbest.fitness) {
                this.gbest = particle;
            }
        }
    }

    update_particles() {
        for (const particle of this.particles) {
            particle.update_velocity(this.gbest);
            particle.update_position();
        }
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    fitness: number;

    constructor(dimensions: number, bounds: [number, number]) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * (bounds[1] - bounds[0]) + bounds[0]);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.best_position = this.position.slice();
        this.fitness = Infinity;
    }

    update_velocity(gbest: Particle) {
        const w = 0.5, c1 = 1.5, c2 = 1.5;
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = Math.random(), r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (gbest.position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (this.position[i] < this.bounds[0]) {
                this.position[i] = this.bounds[0];
            }
            if (this.position[i] > this.bounds[1]) {
                this.position[i] = this.bounds[1];
            }
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function optimize(swarm: Swarm, max_iterations: number) {
    for (let _ = 0; _ < max_iterations; _++) {
        swarm.update_gbest();
        for (const particle of swarm.particles) {
            particle.fitness = objective_function(particle.position);
        }
        swarm.update_particles();
    }
}

function main() {
    const size = 30;
    const dimensions = 2;
    const bounds: [number, number] = [-10, 10];
    const max_iterations = 100;
    const swarm = new Swarm(size, dimensions, bounds);
    optimize(swarm, max_iterations);
    console.log(swarm.gbest?.position);
}

main();