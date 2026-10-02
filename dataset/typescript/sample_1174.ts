class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_score: number;

    constructor(dimensions: number) {
        this.position = new Array(dimensions).fill(0.0);
        this.velocity = new Array(dimensions).fill(0.0);
        this.best_position = new Array(dimensions).fill(0.0);
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], w: number, c1: number, c2: number): void {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = 0.5;
            const r2 = 0.5;
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds: [number, number][]): void {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(this.position[i], bounds[i][1]));
        }
    }

    evaluate(score_function: (position: number[]) => number): void {
        this.best_score = score_function(this.position);
        if (this.best_score < score_function(this.best_position)) {
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[];
    global_best_score: number;
    bounds: [number, number][];
    w: number;
    c1: number;
    c2: number;

    constructor(dimensions: number, num_particles: number, bounds: [number, number][], w: number, c1: number, c2: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = new Array(dimensions).fill(0.0);
        this.global_best_score = Infinity;
        this.bounds = bounds;
        this.w = w;
        this.c1 = c1;
        this.c2 = c2;
    }

    update_global_best(): void {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best = [...particle.best_position];
            }
        }
    }

    iterate(score_function: (position: number[]) => number): void {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best, this.w, this.c1, this.c2);
            particle.update_position(this.bounds);
            particle.evaluate(score_function);
        }
        this.update_global_best();
    }
}

function main(): void {
    const dimensions = 2;
    const num_particles = 10;
    const bounds: [number, number][] = [[-10, 10], [-10, 10]];
    const w = 0.7;
    const c1 = 2.0;
    const c2 = 2.0;

    const score_function = (position: number[]): number => {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    };

    const swarm = new Swarm(dimensions, num_particles, bounds, w, c1, c2);
    while (true) {
        swarm.iterate(score_function);
    }
}

main();