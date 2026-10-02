import Foundation

func initializeParticles(size: Int, dimensions: Int) -> [[String: Any]] {
    var particles = [[String: Any]]()
    for _ in 0..<size {
        let position = (0..<dimensions).map { _ in Double.random(in: -10...10) }
        let velocity = (0..<dimensions).map { _ in Double.random(in: -1...1) }
        let pbestPosition = position
        let pbestValue = Double.greatestFiniteMagnitude
        particles.append(["position": position, "velocity": velocity, "pbest_position": pbestPosition, "pbest_value": pbestValue])
    }
    return particles
}

func updateVelocity(particles: inout [[String: Any]], gbestPosition: [Double], w: Double = 0.7, c1: Double = 1.5, c2: Double = 1.5) {
    for particle in particles {
        guard let position = particle["position"] as? [Double], let velocity = particle["velocity"] as? [Double], let pbestPosition = particle["pbest_position"] as? [Double] else { continue }
        for i in 0..<position.count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let cognitive = c1 * r1 * (pbestPosition[i] - position[i])
            let social = c2 * r2 * (gbestPosition[i] - position[i])
            let newVelocity = w * velocity[i] + cognitive + social
            particle["velocity"] = (particle["velocity"] as? [Double])?.enumerated().map { index, val -> Double in index == i ? newVelocity : val }
        }
    }
}

func updatePosition(particles: inout [[String: Any]], bounds: (Double, Double)) {
    for particle in particles {
        guard let position = particle["position"] as? [Double], let velocity = particle["velocity"] as? [Double] else { continue }
        for i in 0..<position.count {
            let newPosition = position[i] + velocity[i]
            particle["position"] = (particle["position"] as? [Double])?.enumerated().map { index, val -> Double in index == i ? min(bounds.1, max(bounds.0, newPosition)) : val }
        }
    }
}

func evaluate(particles: inout [[String: Any]], objectiveFunction: ([Double]) -> Double) {
    for particle in particles {
        guard let position = particle["position"] as? [Double], let pbestValue = particle["pbest_value"] as? Double else { continue }
        let value = objectiveFunction(position)
        if value < pbestValue {
            particle["pbest_value"] = value
            particle["pbest_position"] = position
        }
    }
}

func findGbest(particles: [[String: Any]]) -> [Double]? {
    var gbestValue = Double.greatestFiniteMagnitude
    var gbestPosition: [Double]?
    for particle in particles {
        guard let pbestValue = particle["pbest_value"] as? Double, let pbestPosition = particle["pbest_position"] as? [Double] else { continue }
        if pbestValue < gbestValue {
            gbestValue = pbestValue
            gbestPosition = pbestPosition
        }
    }
    return gbestPosition
}

func optimize(objectiveFunction: ([Double]) -> Double, dimensions: Int, size: Int, iterations: Int, bounds: (Double, Double)) -> [Double]? {
    var particles = initializeParticles(size: size, dimensions: dimensions)
    guard let gbestPosition = findGbest(particles: particles) else { return nil }
    for _ in 0..<iterations {
        updateVelocity(particles: &particles, gbestPosition: gbestPosition)
        updatePosition(particles: &particles, bounds: bounds)
        evaluate(particles: &particles, objectiveFunction: objectiveFunction)
        guard let newGbestPosition = findGbest(particles: particles) else { return nil }
        gbestPosition = newGbestPosition
    }
    return gbestPosition
}

func main() {
    func sphereFunction(x: [Double]) -> Double {
        return x.reduce(0) { $0 + $1 * $1 }
    }
    let dimensions = 30
    let size = 30
    let iterations = 100
    let bounds = (-10, 10)
    if let result = optimize(objectiveFunction: sphereFunction, dimensions: dimensions, size: size, iterations: iterations, bounds: bounds) {
        print(result)
    }
}

main()