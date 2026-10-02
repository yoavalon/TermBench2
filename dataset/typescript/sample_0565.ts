class Swarm {
    size: number;
    dimensions: number;
    positions: number[][];
    velocities: number[][];

    constructor(size: number, dimensions: number) {
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

    update_velocities(global_best: number[]) {
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.dimensions; j++) {
                this.velocities[i][j] = 0.5 * this.velocities[i][j] + 1.5 * (global_best[j] - this.positions[i][j]);
            }
        }
    }
}

class Environment {
    swarm: Swarm;
    global_best: number[];

    constructor(swarm: Swarm) {
        this.swarm = swarm;
        this.global_best = Array(swarm.dimensions).fill(0);
    }

    evaluate() {
        for (const pos of this.swarm.positions) {
            const fitness = pos.reduce((acc, val) => acc + val, 0);
            if (fitness > this.global_best.reduce((acc, val) => acc + val, 0)) {
                this.global_best = [...pos];
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
    const swarm = new Swarm(10, 2);
    const env = new Environment(swarm);
    env.run();
}

main();