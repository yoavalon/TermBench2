class Swarm {
    particles: Particle[];
    best_position: Position | null;

    constructor(size: number, dimensions: number) {
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.best_position = null;
    }

    update_best_position() {
        if (!this.best_position) {
            this.best_position = this.particles[0].position;
        } else {
            for (const particle of this.particles) {
                if (particle.fitness > this.best_position.fitness) {
                    this.best_position = particle.position;
                }
            }
        }
    }

    update_particles(iterations: number) {
        if (iterations > 0) {
            for (const particle of this.particles) {
                particle.update_velocity(this.best_position!);
                particle.update_position();
            }
            this.update_best_position();
            this.update_particles(iterations - 1);
        }
    }
}

class Particle {
    position: number[];
    velocity: number[];
    fitness: number;

    constructor(dimensions: number) {
        this.position = Array(dimensions).fill(0.0);
        this.velocity = Array(dimensions).fill(0.0);
        this.fitness = 0.0;
    }

    update_velocity(best_position: Position) {
        const w = 0.7, c1 = 1.5, c2 = 1.5;
        for (let i = 0; i < this.position.length; i++) {
            const r1 = 0.5, r2 = 0.5;
            const cognitive = c1 * r1 * (best_position[i] - this.position[i]);
            const social = c2 * r2 * (this.best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.fitness = this.calculate_fitness();
        }
    }

    calculate_fitness() {
        return this.position.reduce((sum, x) => sum + x ** 2, 0);
    }
}

type Position = number[];

function optimize(swarm: Swarm, iterations: number) {
    swarm.update_particles(iterations);
}

function main() {
    const dimensions = 2;
    const swarm_size = 10;
    const iterations = 50;
    const swarm = new Swarm(swarm_size, dimensions);
    optimize(swarm, iterations);
}

main();