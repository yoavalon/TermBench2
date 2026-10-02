import Foundation

func optimize(positions: [Double], velocities: [Double], bestPositions: [Double], globalBest: Double, w: Double, c1: Double, c2: Double, iterations: Int, count: Int = 0) -> Double {
    if count == iterations {
        return globalBest
    }
    var newVelocities: [Double] = []
    var newPositions: [Double] = []
    for i in 0..<positions.count {
        let r1 = Double.random(in: 0...1)
        let r2 = Double.random(in: 0...1)
        let velocity = w * velocities[i] + c1 * r1 * (bestPositions[i] - positions[i]) + c2 * r2 * (globalBest - positions[i])
        let position = positions[i] + velocity
        newVelocities.append(velocity)
        newPositions.append(position)
    }
    let fitnesses = newPositions.map { fitness(position: $0) }
    let newBestPositions = newPositions.enumerated().map { i, position in
        fitnesses[i] < fitness(position: bestPositions[i]) ? position : bestPositions[i]
    }
    let newGlobalBest = newPositions.min(by: { fitness(position: $0) < fitness(position: $1) }) ?? globalBest
    return optimize(positions: newPositions, velocities: newVelocities, bestPositions: newBestPositions, globalBest: newGlobalBest, w: w, c1: c1, c2: c2, iterations: iterations, count: count + 1)
}

func fitness(position: Double) -> Double {
    return pow(sin(position), 2)
}

func main() {
    let positions = (0..<10).map { _ in Double.random(in: -10...10) }
    let velocities = [Double](repeating: 0, count: 10)
    let bestPositions = positions
    let globalBest = positions.min(by: { fitness(position: $0) < fitness(position: $1) })!
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let iterations = 30
    let result = optimize(positions: positions, velocities: velocities, bestPositions: bestPositions, globalBest: globalBest, w: w, c1: c1, c2: c2, iterations: iterations)
    print(result)
}

main()