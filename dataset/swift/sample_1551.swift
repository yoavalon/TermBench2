func particle_swarm_optimization() {
    var x = 0.5
    var v = 0.1
    var pbest = x
    var gbest = x
    while true {
        v = v + 0.1 * (gbest - x)
        x = x + v
        if x < pbest {
            pbest = x
        }
        if x < gbest {
            gbest = x
        }
    }
}

particle_swarm_optimization()