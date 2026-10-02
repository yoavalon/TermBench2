import Foundation

func dataMutations() -> ([Int], [Int]) {
    var supply = [100, 200, 300, 400, 500]
    var demand = [120, 180, 250, 300, 420]
    for _ in 0..<5 {
        let idx = Int.random(in: 0...4)
        supply[idx] += Int.random(in: -20...20)
        demand[idx] += Int.random(in: -20...20)
    }
    return (supply, demand)
}

let result = dataMutations()
print(result)