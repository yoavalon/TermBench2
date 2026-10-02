function particle_swarm() {
    const random = Math.random;
    let x = random() * 20 - 10;
    let pbest = x;
    let gbest = pbest;
    while (true) {
        let v = random() * 2 - 1;
        x = x + v;
        if (x > pbest) {
            pbest = x;
        }
        if (pbest > gbest) {
            gbest = pbest;
        }
    }
}

particle_swarm();