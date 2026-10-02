func optimize(iterations: Int, particles: Int, dimensions: Int) -> [Double] {
    var velocity = Array(repeating: Array(repeating: 0.0, count: dimensions), count: particles)
    var position = Array(repeating: Array(repeating: 0.0, count: dimensions), count: particles)
    var best_position = Array(repeating: Array(repeating: 0.0, count: dimensions), count: particles)
    var global_best = Array(repeating: 0.0, count: dimensions)
    
    for _ in 0..<iterations {
        for i in 0..<particles {
            for j in 0..<dimensions {
                velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j])
                position[i][j] += velocity[i][j]
            }
        }
    }
    return global_best
}

optimize(iterations: 100, particles: 20, dimensions: 3)