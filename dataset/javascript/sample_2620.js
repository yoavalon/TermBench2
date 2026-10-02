class Swarm {
    constructor(size, dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.velocities = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_scores = new Array(size).fill(Infinity);
    }

    update_best_positions(scores) {
        for (let i = 0; i < this.size; i++) {
            if (scores[i] < this.best_scores[i]) {
                this.best_scores[i] = scores[i];
                this.best_positions[i] = this.positions[i].slice();
            }
        }
    }

    update_velocities(global_best_position, w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                const r1 = 0.5, r2 = 0.5;
                this.velocities[i][j] = w * this.velocities[i][j] + c1 * r1 * (this.best_positions[i][j] - this.positions[i][j]) + c2 * r2 * (global_best_position[j] - this.positions[i][j]);
            }
        }
    }

    update_positions() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.positions[i][j] += this.velocities[i][j];
            }
        }
    }
}

function fitness_function(position) {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main() {
    const swarm_size = 30;
    const dimensions = 2;
    const max_iterations = 100;
    const swarm = new Swarm(swarm_size, dimensions);
    for (let iteration = 0; iteration < max_iterations; iteration++) {
        const scores = swarm.positions.map(position => fitness_function(position));
        const global_best_index = scores.indexOf(Math.min(...scores));
        const global_best_position = swarm.positions[global_best_index];
        swarm.update_best_positions(scores);
        swarm.update_velocities(global_best_position);
        swarm.update_positions();
    }
    const best_score = Math.min(...scores);
    const best_position = swarm.positions[scores.indexOf(best_score)];
    console.log('Best score:', best_score);
    console.log('Best position:', best_position);
}

main();