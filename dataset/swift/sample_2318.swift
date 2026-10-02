import Foundation

func initializeParticles(dimensions: Int, count: Int) -> [[String: Any]] {
    var particles: [[String: Any]] = []
    for _ in 0..<count {
        let position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        let velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        particles.append(["position": position, "velocity": velocity, "best_position": position])
    }
    return particles
}

func evaluateFitness(particles: inout [[String: Any]], objectiveFunction: (Any) -> Double) {
    for i in 0..<particles.count {
        let position = particles[i]["position"] as! [Double]
        particles[i]["fitness"] = objectiveFunction(position)
    }
}

func updateParticles(particles: inout [[String: Any]], globalBest: [String: Any], inertiaWeight: Double, cognitiveWeight: Double, socialWeight: Double) {
    for i in 0..<particles.count {
        let particle = particles[i]
        let position = particle["position"] as! [Double]
        let velocity = particle["velocity"] as! [Double]
        let bestPosition = particle["best_position"] as! [Double]
        let globalBestPosition = globalBest["position"] as! [Double]
        
        for j in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitiveVelocity = cognitiveWeight * r1 * (bestPosition[j] - position[j])
            let socialVelocity = socialWeight * r2 * (globalBestPosition[j] - position[j])
            let newVelocity = inertiaWeight * velocity[j] + cognitiveVelocity + socialVelocity
            particles[i]["velocity"] as! [Double][j] = newVelocity
            particles[i]["position"] as! [Double][j] += newVelocity
        }
        
        let newBestPosition = particles[i]["position"] as! [Double]
        let newFitness = particles[i]["fitness"] as! Double
        let currentBestFitness = particle["best_position"] as! [Double]
        if newFitness < particles[i]["fitness"] as! Double {
            particles[i]["best_position"] = newBestPosition
        }
    }
}

func findGlobalBest(particles: [[String: Any]]) -> [String: Any] {
    var globalBest = particles[0]
    for i in 1..<particles.count {
        let fitness = particles[i]["fitness"] as! Double
        if fitness < globalBest["fitness"] as! Double {
            globalBest = particles[i]
        }
    }
    return globalBest
}

func objectiveFunction(position: Any) -> Double {
    let positionArray = position as! [Double]
    return positionArray.map { $0 * $0 }.reduce(0, +)
}

func main() {
    let dimensions = 2
    let particleCount = 30
    let inertiaWeight = 0.7
    let cognitiveWeight = 1.5
    let socialWeight = 1.5
    var particles = initializeParticles(dimensions: dimensions, count: particleCount)
    while true {
        evaluateFitness(particles: &particles, objectiveFunction: objectiveFunction)
        let globalBest = findGlobalBest(particles: particles)
        updateParticles(particles: &particles, globalBest: globalBest, inertiaWeight: inertiaWeight, cognitiveWeight: cognitiveWeight, socialWeight: socialWeight)
    }
}

main()