class Swarm {
    constructor(size, dimensions, bounds) {
        this.size = size;
        this.dimensions = dimensions;
        this.bounds = bounds;
        this.positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.velocities = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.pbest_positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.pbest_scores = Array(size).fill(Infinity);
        this.gbest_position = Array(dimensions).fill(0.0);
        this.gbest_score = Infinity;
    }

    initialize() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.positions[i][j] = (this.bounds[j][1] - this.bounds[j][0]) * Math.random() + this.bounds[j][0];
                this.velocities[i][j] = (this.bounds[j][1] - this.bounds[j][0]) * Math.random() - (this.bounds[j][1] - this.bounds[j][0]) / 2;
            }
        }
    }

    evaluate(function) {
        for (let i = 0; i < this.size; i++) {
            const score = function(this.positions[i]);
            if (score < this.pbest_scores[i]) {
                this.pbest_scores[i] = score;
                this.pbest_positions[i] = [...this.positions[i]];
            }
            if (score < this.gbest_score) {
                this.gbest_score = score;
                this.gbest_position = [...this.positions[i]];
            }
        }
    }

    update_velocities(w, c1, c2) {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.velocities[i][j] = w * this.velocities[i][j] + c1 * Math.random() * (this.pbest_positions[i][j] - this.positions[i][j]) + c2 * Math.random() * (this.gbest_position[j] - this.positions[i][j]);
            }
        }
    }

    update_positions() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.positions[i][j] += this.velocities[i][j];
                this.positions[i][j] = Math.max(this.bounds[j][0], Math.min(this.bounds[j][1], this.positions[i][j]));
            }
        }
    }

    optimize(function, iterations) {
        this.initialize();
        for (let _ = 0; _ < iterations; _++) {
            this.evaluate(function);
            this.update_velocities(0.7, 1.5, 1.5);
            this.update_positions();
        }
        return this.gbest_score;
    }
}

function objective(x) {
    return x.reduce((sum, xi) => sum + Math.pow(xi - 0.5, 2), 0);
}

function main() {
    const dimensions = 3;
    const bounds = Array(dimensions).fill([-10, 10]);
    const swarm_size = 30;
    const iterations = 100;
    const swarm = new Swarm(swarm_size, dimensions, bounds);
    const best_score = swarm.optimize(objective, iterations);
    console.log(best_score);
}

main();