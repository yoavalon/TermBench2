class Swarm {
    constructor(size, dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.velocities = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_positions = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
        this.best_scores = Array(size).fill(Infinity);
        this.global_best_position = Array(dimensions).fill(0.0);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (let i = 0; i < this.size; i++) {
            const score = this.evaluate(this.best_positions[i]);
            if (score < this.global_best_score) {
                this.global_best_score = score;
                this.global_best_position = [...this.best_positions[i]];
            }
        }
    }

    evaluate(position) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }

    update_particles() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                const r1 = 0.5, r2 = 0.5;
                const c1 = 2.0, c2 = 2.0;
                this.velocities[i][j] = 0.7 * this.velocities[i][j] + c1 * r1 * (this.best_positions[i][j] - this.positions[i][j]) + c2 * r2 * (this.global_best_position[j] - this.positions[i][j]);
                this.positions[i][j] += this.velocities[i][j];
            }
            this.best_scores[i] = this.evaluate(this.positions[i]);
            if (this.best_scores[i] < this.global_best_score) {
                this.best_positions[i] = [...this.positions[i]];
            }
        }
    }

    iterate() {
        this.update_global_best();
        this.update_particles();
        this.iterate();
    }
}

function main() {
    const swarm = new Swarm(30, 2);
    swarm.iterate();
}

main();