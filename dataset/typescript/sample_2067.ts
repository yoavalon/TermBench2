class Particle {
    position: number[];
    velocity: number[];
    best_pos: number[];
    best_score: number;

    constructor(dim: number) {
        this.position = new Array(dim).fill(0.0);
        this.velocity = new Array(dim).fill(0.0);
        this.best_pos = new Array(dim).fill(0.0);
        this.best_score = Infinity;
    }

    update_velocity(global_best: number[], w: number, c1: number, c2: number) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.best_pos[i] - this.position[i]) + c2 * r2 * (global_best[i] - this.position[i]);
        }
    }

    update_position(bounds: [number[], number[]]) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[0][i], Math.min(bounds[1][i], this.position[i]));
        }
    }
}

class Swarm {
    particles: Particle[];
    best_global_pos: number[];
    best_global_score: number;

    constructor(num_particles: number, dim: number, bounds: [number[], number[]]) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dim));
        this.best_global_pos = new Array(dim).fill(0.0);
        this.best_global_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.best_global_score) {
                this.best_global_score = particle.best_score;
                this.best_global_pos = [...particle.best_pos];
            }
        }
    }

    optimize(fitness_func: (position: number[]) => number, max_iter: number, w: number, c1: number, c2: number) {
        for (let _ = 0; _ < max_iter; _++) {
            for (const particle of this.particles) {
                particle.update_velocity(this.best_global_pos, w, c1, c2);
                particle.update_position(bounds);
                const score = fitness_func(particle.position);
                if (score < particle.best_score) {
                    particle.best_score = score;
                    particle.best_pos = [...particle.position];
                }
            }
            this.update_global_best();
        }
    }
}

function fitness_function(position: number[]): number {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main() {
    const num_particles = 30;
    const dim = 2;
    const bounds: [number[], number[]] = [new Array(dim).fill(0.0), new Array(dim).fill(10.0)];
    const max_iter = 100;
    const w = 0.7;
    const c1 = 2.0;
    const c2 = 2.0;
    const swarm = new Swarm(num_particles, dim, bounds);
    swarm.optimize(fitness_function, max_iter, w, c1, c2);
    console.log(swarm.best_global_pos, swarm.best_global_score);
}

main();