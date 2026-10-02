import Foundation

func optimize(_ positions: [Double], _ velocities: [Double], _ personalBest: [Double], _ globalBest: Double, _ iteration: Int, _ maxIterations: Int) -> Double {
    if iteration >= maxIterations {
        return globalBest
    }
    var newPositions = [Double]()
    var newVelocities = [Double]()
    for i in 0..<positions.count {
        let r1 = Double.random(in: 0...1)
        let r2 = Double.random(in: 0...1)
        let newVelocity = velocities[i] + 2 * r1 * (personalBest[i] - positions[i]) + 2 * r2 * (globalBest - positions[i])
        let newPosition = positions[i] + newVelocity
        newPositions.append(newPosition)
        newVelocities.append(newVelocity)
    }
    let newGlobalBest = newPositions.min(by: { fitness($0) < fitness($1) })!
    return optimize(newPositions, newVelocities, personalBest, newGlobalBest, iteration + 1, maxIterations)
}

func fitness(_ x: Double) -> Double {
    return x * x
}

func main() {
    let positions = (0..<10).map { _ in Double.random(in: -10...10) }
    let velocities = [Double](repeating: 0.0, count: 10)
    let personalBest = positions
    let globalBest = positions.min(by: { fitness($0) < fitness($1) })!
    _ = optimize(positions, velocities, personalBest, globalBest, 0, 100)
}

main()