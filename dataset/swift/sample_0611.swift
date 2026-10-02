import Foundation

func monte_carlo_pricing(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let dt = T / Double(N)
    var paths = [[S]](repeating: [S], count: M)
    for _ in 1...N {
        for j in 0..<M {
            let Z = Double.random(in: 0...1)
            let g = sqrt(-2 * log(Z)) * cos(2 * Double.pi * Z)
            paths[j].append(paths[j].last! * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * g))
        }
    }
    return exp(-r * T) * paths.map { max($0.last! - K, 0) }.reduce(0, +) / Double(M)
}

monte_carlo_pricing(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 100, M: 10000)