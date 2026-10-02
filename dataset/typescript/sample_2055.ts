import * as random from 'random';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(-10, 10));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }
}

class Swarm {
    particles: Particle[];
    global_best_position: number[];
    global_best_score: number;

    constructor(num_particles: number, dimensions: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best_position = Array(dimensions).fill(0.0);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            const score = this.evaluate(particle.position);
            if (score < this.global_best_score) {
                this.global_best_score = score;
                this.global_best_position = [...particle.position];
            }
        }
    }

    evaluate(position: number[]) {
        return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
    }

    update_particles(w: number, c1: number, c2: number) {
        for (const particle of this.particles) {
            for (let i = 0; i < particle.position.length; i++) {
                const r1 = random.random();
                const r2 = random.random();
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (this.global_best_position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
                particle.best_score = Math.min(particle.best_score, this.evaluate(particle.position));
                particle.best_position = particle.best_score < this.evaluate(particle.best_position) ? [...particle.position] : [...particle.best_position];
            }
        }
    }
}

function main() {
    const dimensions = 30;
    const num_particles = 30;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 100;
    const swarm = new Swarm(num_particles, dimensions);
    for (let i = 0; i < iterations; i++) {
        swarm.update_global_best();
        swarm.update_particles(w, c1, c2);
    }
    console.log('Best score:', swarm.global_best_score);
}

main();