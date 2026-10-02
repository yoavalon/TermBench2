class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * 20 - 10);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }
}

class Swarm {
    particles: Particle[];
    gbest_position: number[] | null;
    gbest_score: number;

    constructor(num_particles: number, dimensions: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.gbest_position = null;
        this.gbest_score = Infinity;
    }

    update_gbest() {
        for (const particle of this.particles) {
            if (particle.best_score < this.gbest_score) {
                this.gbest_score = particle.best_score;
                this.gbest_position = [...particle.best_position];
            }
        }
    }

    update_particles(w: number, c1: number, c2: number) {
        for (const particle of this.particles) {
            for (let i = 0; i < particle.position.length; i++) {
                const r1 = Math.random();
                const r2 = Math.random();
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (this.gbest_position![i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
            }
        }
    }

    evaluate(objective_function: (x: number[]) => number) {
        for (const particle of this.particles) {
            const score = objective_function(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = [...particle.position];
            }
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 3;
    const num_particles = 20;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 100;
    const swarm = new Swarm(num_particles, dimensions);
    for (let i = 0; i < iterations; i++) {
        swarm.update_gbest();
        swarm.update_particles(w, c1, c2);
        swarm.evaluate(objective_function);
    }
    console.log('Best score:', swarm.gbest_score);
    console.log('Best position:', swarm.gbest_position);
}

main();