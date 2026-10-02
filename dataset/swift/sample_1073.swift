import Foundation

func updatePosition(_ position: Double, _ velocity: Double, _ p_best: Double, _ g_best: Double) -> (Double, Double) {
    let r1 = Double.random(in: 0...1)
    let r2 = Double.random(in: 0...1)
    let c1 = 1.5
    let c2 = 1.5
    let new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position)
    let new_position = position + new_velocity
    return (new_position, new_velocity)
}

func optimize() {
    var particles = [
        ["position": Double.random(in: -10...10), "velocity": Double.random(in: -1...1), "p_best": Optional<Double>.none]
    ]
    var g_best = particles[0]["position"]!

    while true {
        for var particle in particles {
            if particle["p_best"] == nil {
                particle["p_best"] = particle["position"]
            } else if particle["position"]! < particle["p_best"]! {
                particle["p_best"] = particle["position"]
            }
            if particle["position"]! < g_best {
                g_best = particle["position"]!
            }
        }

        for i in 0..<particles.count {
            let (new_position, new_velocity) = updatePosition(particles[i]["position"]!, particles[i]["velocity"]!, particles[i]["p_best"]!, g_best)
            particles[i]["position"] = new_position
            particles[i]["velocity"] = new_velocity
        }
    }
}

optimize()