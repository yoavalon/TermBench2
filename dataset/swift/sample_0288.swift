import Foundation
import Accelerate

class StateSimulator {
    var conditions: [Double]
    var boundaries: (Double, Double)
    var iteration: Int = 0

    init(initial_conditions: [Double], boundary_conditions: (Double, Double)) {
        self.conditions = initial_conditions
        self.boundaries = boundary_conditions
    }

    func update_conditions() {
        var randomValues = [Double](repeating: 0.0, count: conditions.count)
        vvsrand(&randomValues, conditions.count)
        for i in 0..<conditions.count {
            conditions[i] += randomValues[i] * 0.1
            conditions[i] = max(min(conditions[i], boundaries.1), boundaries.0)
        }
    }

    func check_stability() -> Bool {
        let lowerBound = boundaries.0
        let upperBound = boundaries.1
        for condition in conditions {
            if abs(condition - lowerBound) <= 0.01 || abs(condition - upperBound) <= 0.01 {
                return true
            }
        }
        return false
    }
}

class BoundaryConditions {
    var limit1: Double
    var limit2: Double

    init(lower: Double, upper: Double) {
        self.limit1 = lower
        self.limit2 = upper
    }

    func get_boundaries() -> (Double, Double) {
        return (limit1, limit2)
    }
}

func simulate_state(initial: [Double], boundaries: (Double, Double), max_iterations: Int) -> [Double] {
    let simulator = StateSimulator(initial_conditions: initial, boundary_conditions: boundaries)
    for _ in 0..<max_iterations {
        simulator.update_conditions()
        if simulator.check_stability() {
            break
        }
    }
    return simulator.conditions
}

func main() {
    let initial_conditions = [0.5, 0.5, 0.5]
    let boundary_conditions = BoundaryConditions(lower: 0, upper: 1)
    let max_iterations = 100
    let final_state = simulate_state(initial: initial_conditions, boundaries: boundary_conditions.get_boundaries(), max_iterations: max_iterations)
    print(final_state)
}

main()