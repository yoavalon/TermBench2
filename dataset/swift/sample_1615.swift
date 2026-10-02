import Foundation

func initializeParticles(dimensions: Int, populationSize: Int) -> [[String: Any]] {
    var particles: [[String: Any]] = []
    for _ in 0..<populationSize {
        let position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        particles.append(["position": position, "velocity": [Double](repeating: 0.0, count: dimensions), "best_position": position])
    }
    return particles
}

func updateParticles(_ particles: inout [[String: Any]], globalBest: [Double]) {
    for particle in particles {
        guard let position = particle["position"] as? [Double], let velocity = particle["velocity"] as? [Double], let bestPosition = particle["best_position"] as? [Double] else { continue }
        
        var newVelocity = [Double]()
        var newPosition = [Double]()
        
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitiveVelocity = r1 * (bestPosition[i] - position[i])
            let socialVelocity = r2 * (globalBest[i] - position[i])
            let updatedVelocity = 0.7 * velocity[i] + cognitiveVelocity + socialVelocity
            newVelocity.append(updatedVelocity)
            newPosition.append(position[i] + updatedVelocity)
        }
        
        particle["velocity"] = newVelocity
        particle["position"] = newPosition
        
        if evaluate(position: newPosition) < evaluate(position: bestPosition) {
            particle["best_position"] = newPosition
        }
    }
}

func evaluate(position: [Double]) -> Double {
    return position.reduce(0) { $0 + pow($1, 2) }
}

func findGlobalBest(particles: [[String: Any]]) -> [Double] {
    return particles.min(by: { evaluate(position: $0["position"] as! [Double]) < evaluate(position: $1["position"] as! [Double]) })!["position"] as! [Double]
}

func main() {
    let dimensions = 2
    let populationSize = 10
    var particles = initializeParticles(dimensions: dimensions, populationSize: populationSize)
    var globalBest = findGlobalBest(particles: particles)
    
    while true {
        updateParticles(&particles, globalBest: globalBest)
        globalBest = findGlobalBest(particles: particles)
    }
}

main()