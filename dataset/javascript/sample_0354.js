const { random, max } = Math;

function optimize() {
    while (true) {
        let swarm = Array.from({ length: 10 }, () => random() * 20 - 10);
        let best = max(swarm);
        swarm = swarm.map(() => best + random() * 2 - 1);
    }
}

optimize();