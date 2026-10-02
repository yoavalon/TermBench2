import * as random from 'random-js';

class Swarm {
    size: number;
    dimensions: number;
    positions: number[][];
    velocities: number[][];
    best_positions: number[][];
    best_score: number;

    constructor(size: number, dimensions: number) {
        this.size = size;
        this.dimensions = dimensions;
        this.positions = Array.from({ length: size }, () => Array.from({ length: dimensions }, () => random.real(0, 1)()));
        this.velocities = Array.from({ length: size }, () => Array.from({ length: dimensions }, () => random.real(0, 1)()));
        this.best_positions = this.positions.map(p => [...p]);
        this.best_score = Infinity;
    }

    update_personal_best(score: number) {
        if (score < this.best_score) {
            this.best_score = score;
            this.best_positions = this.positions.map(p => [...p]);
        }
    }

    update_velocity(global_best: number[]) {
        const inertia = 0.5;
        const cognitive = 1.5;
        const social = 1.5;
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                const r1 = random.real(0, 1)();
                const r2 = random.real(0, 1)();
                this.velocities[i][j] = inertia * this.velocities[i][j] + cognitive * r1 * (this.best_positions[i][j] - this.positions[i][j]) + social * r2 * (global_best[j] - this.positions[i][j]);
            }
        }
    }

    update_position() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.positions[i][j] += this.velocities[i][j];
            }
        }
    }
}

class Environment {
    swarm: Swarm;

    constructor(swarm: Swarm) {
        this.swarm = swarm;
    }

    evaluate(): number[] {
        const scores: number[] = [];
        for (const position of this.swarm.positions) {
            const score = position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
            scores.push(score);
        }
        return scores;
    }

    find_global_best(scores: number[]): number[] {
        const global_best_index = scores.indexOf(Math.min(...scores));
        return this.swarm.positions[global_best_index];
    }
}

function main() {
    const swarm = new Swarm(10, 3);
    const environment = new Environment(swarm);
    const iterations = 50;
    for (let _ = 0; _ < iterations; _++) {
        const scores = environment.evaluate();
        const global_best = environment.find_global_best(scores);
        swarm.update_personal_best(Math.min(...scores));
        swarm.update_velocity(global_best);
        swarm.update_position();
    }
    console.log(`Best score: ${swarm.best_score}`);
}

main();