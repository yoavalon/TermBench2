class Swarm {
    size: number;
    dimensions: number;
    particles: number[][];
    velocities: number[][];
    best_positions: number[][];
    best_scores: number[];
    global_best: number[];
    global_best_score: number;

    constructor(size: number, dimensions: number) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.velocities = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_scores = Array(size).fill(Infinity);
        this.global_best = Array(dimensions).fill(0.0);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (let i = 0; i < this.size; i++) {
            if (this.best_scores[i] < this.global_best_score) {
                this.global_best_score = this.best_scores[i];
                this.global_best = [...this.best_positions[i]];
            }
        }
    }

    update_particles() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                const r1 = 0.5;
                const r2 = 0.5;
                const cognitive = r1 * (this.best_positions[i][j] - this.particles[i][j]);
                const social = r2 * (this.global_best[j] - this.particles[i][j]);
                this.velocities[i][j] += cognitive + social;
                this.particles[i][j] += this.velocities[i][j];
            }
        }
    }

    evaluate(objective_function: (position: number[]) => number) {
        for (let i = 0; i < this.size; i++) {
            const score = objective_function(this.particles[i]);
            if (score < this.best_scores[i]) {
                this.best_scores[i] = score;
                this.best_positions[i] = [...this.particles[i]];
            }
        }
        this.update_global_best();
    }
}

class Optimization {
    swarm: Swarm;
    objective_function: (position: number[]) => number;

    constructor(swarm: Swarm, objective_function: (position: number[]) => number) {
        this.swarm = swarm;
        this.objective_function = objective_function;
    }

    run() {
        while (true) {
            this.swarm.update_particles();
            this.swarm.evaluate(this.objective_function);
        }
    }
}

function objective_function(position: number[]): number {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

function main() {
    const size = 30;
    const dimensions = 2;
    const swarm = new Swarm(size, dimensions);
    const optimization = new Optimization(swarm, objective_function);
    optimization.run();
}

main();