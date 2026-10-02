import * as random from 'random';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number, bounds: [number, number]) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(bounds[0], bounds[1]));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.best_position[i] - this.position[i]) + c2 * r2 * (global_best[i] - this.position[i]);
        }
    }

    update_position(bounds: [number, number]) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[0], Math.min(bounds[1], this.position[i]));
        }
    }

    evaluate(objective_function: ObjectiveFunction) {
        const score = objective_function(this.position);
        if (score < this.best_score) {
            this.best_score = score;
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best_position: number[];
    global_best_score: number;

    constructor(num_particles: number, dimensions: number, bounds: [number, number]) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions, bounds));
        this.global_best_position = [...this.particles[0].position];
        this.global_best_score = this.particles[0].best_score;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best_position = [...particle.best_position];
            }
        }
    }

    iterate(objective_function: ObjectiveFunction) {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best_position);
            particle.update_position(objective_function.bounds);
            particle.evaluate(objective_function);
        }
        this.update_global_best();
    }
}

class ObjectiveFunction {
    bounds: [number, number];

    constructor(bounds: [number, number]) {
        this.bounds = bounds;
    }

    call(position: number[]) {
        const [x, y] = position;
        return (x ** 2 + y - 11) ** 2 + (x + y ** 2 - 7) ** 2;
    }
}

function main() {
    const dimensions = 2;
    const num_particles = 30;
    const bounds: [number, number] = [-5, 5];
    const objective_function = new ObjectiveFunction(bounds);
    const swarm = new Swarm(num_particles, dimensions, bounds);
    for (let i = 0; i < 100; i++) {
        swarm.iterate(objective_function);
        if (swarm.global_best_score < 1e-06) {
            break;
        }
    }
    console.log('Best position:', swarm.global_best_position);
    console.log('Best score:', swarm.global_best_score);
}

main();