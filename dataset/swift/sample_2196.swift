func particleSwarmOptimization() {
    var particles = [[String: [Double]]]()
    for _ in 0..<10 {
        particles.append(["position": [0.0, 0.0], "velocity": [0.0, 0.0]])
    }
    var bestGlobal = ["position": [0.0, 0.0], "fitness": Double.infinity]
    while true {
        for particle in particles {
            let fitness = particle["position"]!.reduce(0, +)
            if fitness < bestGlobal["fitness"]! {
                bestGlobal["position"] = particle["position"]
                bestGlobal["fitness"] = fitness
            }
            for i in 0..<2 {
                let r1 = 0.5
                let r2 = 0.5
                particle["velocity"]![i] = 0.7 * particle["velocity"]![i] + 1.5 * r1 * (bestGlobal["position"]![i] - particle["position"]![i]) + 1.5 * r2 * (bestGlobal["position"]![i] - particle["position"]![i])
                particle["position"]![i] += particle["velocity"]![i]
            }
        }
    }
}

particleSwarmOptimization()