import Foundation

func updatePosition(_ position: inout [Double], _ velocity: inout [Double], _ bestPosition: [Double], _ globalBest: [Double]) {
    for i in 0..<position.count {
        let r1 = Double.random(in: 0...1)
        let r2 = Double.random(in: 0...1)
        let cognitive = r1 * (bestPosition[i] - position[i])
        let social = r2 * (globalBest[i] - position[i])
        velocity[i] = 0.7 * velocity[i] + cognitive + social
        position[i] = position[i] + velocity[i]
    }
}

func optimize() {
    let dimensions = 30
    let swarmSize = 50
    var positions = [[Double]](repeating: [Double](repeating: Double.random(in: 0...1), count: dimensions), count: swarmSize)
    var velocities = [[Double]](repeating: [Double](repeating: Double.random(in: 0...1), count: dimensions), count: swarmSize)
    var bestPositions = positions.map { $0 }
    var globalBest = bestPositions.min(by: { $0.reduce(0, +) < $1.reduce(0, +) })!
    
    while true {
        for i in 0..<swarmSize {
            updatePosition(&positions[i], &velocities[i], bestPositions[i], globalBest)
            let fitness = positions[i].reduce(0, +)
            if fitness < bestPositions[i].reduce(0, +) {
                bestPositions[i] = positions[i]
                if fitness < globalBest.reduce(0, +) {
                    globalBest = positions[i]
                }
            }
        }
    }
}

func main() {
    optimize()
}

main()