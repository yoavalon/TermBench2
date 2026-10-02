import { random } from 'mathjs';

class Swarm {
    size: number;
    dimensions: number;
    particles: Particle[];
    best_position: number[] | null;
    best_value: number;

    constructor(size: number, dimensions: number) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.best_position = null;
        this.best_value = Infinity;
    }

    update_best() {
        for (const particle of this.particles) {
            if (particle.value < this.best_value) {
                this.best_value = particle.value;
                this.best_position = [...particle.position];
            }
        }
    }

    optimize(iterations: number) {
        for (let _ = 0; _ < iterations; _++) {
            for (const particle of this.particles) {
                particle.update(this.best_position!);
            }
            this.update_best();
        }
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_value: number;

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => random(-10, 10));
        this.velocity = Array.from({ length: dimensions }, () => random(-1, 1));
        this.best_position = [...this.position];
        this.best_value = this.calculate_value();
    }

    calculate_value() {
        return this.position.reduce((sum, x) => sum + x ** 2, 0);
    }

    update(global_best: number[]) {
        const w = 0.7;
        const c1 = 1.5;
        const c2 = 1.5;
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random(0, 1);
            const r2 = random(0, 1);
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.best_position[i] - this.position[i]) + c2 * r2 * (global_best[i] - this.position[i]);
            this.position[i] += this.velocity[i];
        }
        this.value = this.calculate_value();
        if (this.value < this.best_value) {
            this.best_value = this.value;
            this.best_position = [...this.position];
        }
    }
}

function main() {
    const dimensions = 2;
    const swarm_size = 30;
    const iterations = 100;
    const swarm = new Swarm(swarm_size, dimensions);
    swarm.optimize(iterations);
    console.log('Best position:', swarm.best_position);
    console.log('Best value:', swarm.best_value);
}

main();