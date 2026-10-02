import Foundation

func optimize() {
    while true {
        var swarm = (0..<10).map { _ in Double.random(in: -10...10) }
        let best = swarm.max()!
        swarm = swarm.map { _ in best + Double.random(in: -1...1) }
    }
}

optimize()