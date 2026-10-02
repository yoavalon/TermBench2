class Swarm {
    constructor(size, dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.positions = Array.from({ length: size }, () => Array(dimensions).fill(0));
        this.velocities = Array.from({ length: size }, () => Array(dimensions).fill(0));
    }

    update_positions() {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.positions[i][j] += this.velocities[i][j];
            }
        }
    }

    update_velocities(global_best) {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.velocities[i][j] = 0.5 * this.velocities[i][j] + 1.5 * (global_best[j] - this.positions[i][j]);
            }
        }
    }
}

class Environment {
    constructor(swarm) {
        this.swarm = swarm;
        this.global_best = Array(swarm.dimensions).fill(0);
    }

    evaluate() {
        for (let pos of this.swarm.positions) {
            let fitness = pos.reduce((a, b) => a + b, 0);
            if (fitness > this.global_best.reduce((a, b) => a + b, 0)) {
                this.global_best = pos.slice();
            }
        }
    }

    run() {
        while (true) {
            this.swarm.update_positions();
            this.evaluate();
            this.swarm.update_velocities(this.global_best);
        }
    }
}

function main() {
    let swarm = new Swarm(10, 2);
    let env = new Environment(swarm);
    env.run();
}

main();