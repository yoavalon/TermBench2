import Foundation

func initializeParticles(numParticles: Int, dimensions: Int) -> [[String: Any]] {
    var particles: [[String: Any]] = []
    for _ in 0..<numParticles {
        let position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        let velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        particles.append(["position": position, "velocity": velocity, "best_position": position])
    }
    return particles
}

func evaluateFitness(particles: inout [[String: Any]], fitnessFunction: ([Double]) -> Double) {
    for i in 0..<particles.count {
        particles[i]["fitness"] = fitnessFunction(particles[i]["position"] as! [Double])
    }
}

func updateParticles(particles: inout [[String: Any]], globalBestPosition: [Double], inertiaWeight: Double, cognitiveWeight: Double, socialWeight: Double) {
    for i in 0..<particles.count {
        let particle = particles[i]
        let position = particle["position"] as! [Double]
        let velocity = particle["velocity"] as! [Double]
        let bestPosition = particle["best_position"] as! [Double]
        for j in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitiveVelocity = cognitiveWeight * r1 * (bestPosition[j] - position[j])
            let socialVelocity = socialWeight * r2 * (globalBestPosition[j] - position[j])
            particles[i]["velocity"] as! [Double][j] = inertiaWeight * velocity[j] + cognitiveVelocity + socialVelocity
            particles[i]["position"] as! [Double][j] += particles[i]["velocity"] as! [Double][j]
        }
        if fitnessFunction(particles[i]["position"] as! [Double]) < fitnessFunction(particles[i]["best_position"] as! [Double]) {
            particles[i]["best_position"] = particles[i]["position"]
        }
    }
}

func findGlobalBest(particles: [[String: Any]]) -> [Double] {
    let bestParticle = particles.min(by: { (p1, p2) -> Bool in
        return (p1["fitness"] as! Double) < (p2["fitness"] as! Double)
    })!
    return bestParticle["position"] as! [Double]
}

func fitnessFunction(position: [Double]) -> Double {
    return position.reduce(0) { $0 + ($1 * $1) }
}

func main() {
    let numParticles = 30
    let dimensions = 2
    let inertiaWeight = 0.7
    let cognitiveWeight = 1.5
    let socialWeight = 1.5
    var particles = initializeParticles(numParticles: numParticles, dimensions: dimensions)
    while true {
        evaluateFitness(particles: &particles, fitnessFunction: fitnessFunction)
        let globalBestPosition = findGlobalBest(particles: particles)
        updateParticles(particles: &particles, globalBestPosition: globalBestPosition, inertiaWeight: inertiaWeight, cognitiveWeight: cognitiveWeight, socialWeight: socialWeight)
    }
}

main()