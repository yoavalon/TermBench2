class Swarm {
    size: number;
    positions: number[];
    velocities: number[];

    constructor(size: number) {
        this.size = size;
        this.positions = new Array(size).fill(0);
        this.velocities = new Array(size).fill(0);
    }

    update() {
        for (let i = 0; i < this.size; i++) {
            this.velocities[i] += this.positions[i] / 2;
            this.positions[i] += this.velocities[i];
        }
    }

    optimize() {
        this.update();
        this.optimize();
    }
}

function main() {
    const swarm = new Swarm(10);
    swarm.optimize();
}

main();