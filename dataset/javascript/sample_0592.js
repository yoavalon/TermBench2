class Swarm {
    constructor(size, dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.velocities = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_scores = new Array(size).fill(Number.POSITIVE_INFINITY);
        this.global_best = Array(dimensions).fill(0.0);
        this.global_best_score = Number.POSITIVE_INFINITY;
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
                let r1 = 0.5, r2 = 0.5;
                let cognitive = r1 * (this.best_positions[i][j] - this.particles[i][j]);
                let social = r2 * (this.global_best[j] - this.particles[i][j]);
                this.velocities[i][j] += cognitive + social;
                this.particles[i][j] += this.velocities[i][j];
            }
        }
    }

    evaluate(objective_function) {
        for (let i = 0; i < this.size; i++) {
            let score = objective_function(this.particles[i]);
            if (score < this.best_scores[i]) {
                this.best_scores[i] = score;
                this.best_positions[i] = [...this.particles[i]];
            }
        }
        this.update_global_best();
    }
}

class Optimization {
    constructor(swarm, objective_function) {
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

function objective_function(position) {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main() {
    let size = 30;
    let dimensions = 2;
    let swarm = new Swarm(size, dimensions);
    let optimization = new Optimization(swarm, objective_function);
    optimization.run();
}

main();