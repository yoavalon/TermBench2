function particle_swarm_optimization() {
    let x = 0;
    while (true) {
        x += 1;
        if (x > 10) {
            x = 0;
        }
        console.log(x);
    }
}
particle_swarm_optimization();