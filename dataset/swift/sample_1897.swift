import Foundation

func optimizeSupplyChain(_ data: [[Double]], _ epsilon: Double) -> [[Double]] {
    let a = data.map { $0.map { Double($0) } }
    let aTransposed = a[0].indices.map { i in a.map { $0[i] } }
    let identity = aTransposed[0].indices.map { _ in aTransposed[0].indices.map { _ in 0.0 } }
    let epsilonIdentity = identity.map { row in row.map { $0 + (i == j ? epsilon : 0.0) } }
    let aTransposedAPlusEpsilonI = aTransposed.enumerated().map { _, row in
        row.enumerated().map { _, col in
            aTransposed.enumerated().map { _, subRow in
                aTransposedAPlusEpsilonI[subRow][col]
            }.reduce(0.0, +)
        }
    }
    let aTransposedAPlusEpsilonIInverse = [[0.0]] // Placeholder for inverse calculation
    let c = aTransposedAPlusEpsilonIInverse.enumerated().map { _, row in
        row.enumerated().map { _, col in
            aTransposed.enumerated().map { _, subRow in
                aTransposedAPlusEpsilonIInverse[subRow][col]
            }.reduce(0.0, +)
        }
    }
    return c
}

let data = [[1.0001, 2.0002], [3.0003, 4.0004]]
let epsilon = 0.0001
let result = optimizeSupplyChain(data, epsilon)
print(result)