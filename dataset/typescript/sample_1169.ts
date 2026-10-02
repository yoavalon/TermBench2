class Swarm {
    particles: Particle[];
    gbest: Particle;

    constructor(size: number, dimensions: number) {
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.gbest = this.particles[0];
    }

    update_gbest() {
        for (const particle of this.particles) {
            if (particle.fitness < this.gbest.fitness) {
                this.gbest = particle;
            }
        }
    }

    optimize() {
        while (true) {
            for (const particle of this.particles) {
                particle.update_velocity(this.gbest);
                particle.update_position();
            }
            this.update_gbest();
        }
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    fitness: number;

    constructor(dimensions: number) {
        this.position = Array(dimensions).fill(0.0);
        this.velocity = Array(dimensions).fill(0.0);
        this.best_position = [...this.position];
        this.fitness = Infinity;
    }

    update_velocity(gbest: Particle) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = 0.5;
            const r2 = 0.5;
            const inertia = 0.7;
            this.velocity[i] = inertia * this.velocity[i] + r1 * (this.best_position[i] - this.position[i]) + r2 * (gbest.position[i] - this.position[i]);
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (this.fitness > this.calculate_fitness()) {
                this.best_position = [...this.position];
                this.fitness = this.calculate_fitness();
            }
        }
    }

    calculate_fitness() {
        return this.position.reduce((sum, x) => sum + x ** 2, 0);
    }
}

function main() {
    const swarm = new Swarm(10, 2);
    swarm.optimize();
}

main();