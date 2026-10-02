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

    update_velocity(global_best: number[], w: number, c1: number, c2: number) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (this.position[i] < -10) {
                this.position[i] = -10;
            } else if (this.position[i] > 10) {
                this.position[i] = 10;
            }
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[];
    global_best_score: number;

    constructor(num_particles: number, dimensions: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = Array.from({ length: dimensions }, () => Infinity);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best = [...particle.best_position];
                this.global_best_score = particle.best_score;
            }
        }
    }

    optimize(iterations: number, w: number, c1: number, c2: number) {
        for (let _ = 0; _ < iterations; _++) {
            this.update_global_best();
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best, w, c1, c2);
                particle.update_position();
            }
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 30;
    const num_particles = 30;
    const iterations = 100;
    const w = 0.7;
    const c1 = 2.0;
    const c2 = 2.0;
    const swarm = new Swarm(num_particles, dimensions);
    for (const particle of swarm.particles) {
        const score = objective_function(particle.position);
        if (score < particle.best_score) {
            particle.best_score = score;
        }
    }
    swarm.optimize(iterations, w, c1, c2);
    const best_score = swarm.global_best_score;
    console.log('Best Score:', best_score);
}

main();