function particleSwarmOptimization() {
    let x = 0.5;
    let v = 0.1;
    let pbest = x;
    let gbest = x;
    while (true) {
        v = v + 0.1 * (gbest - x);
        x = x + v;
        if (x < pbest) {
            pbest = x;
        }
        if (x < gbest) {
            gbest = x;
        }
    }
}

particleSwarmOptimization();