import Foundation

func optimize_supply_chain(_ data: [Int]) -> [Int] {
    let demand = (0..<data.count).map { _ in Int.random(in: 100...499) }
    let supply = (0..<data.count).map { _ in Int.random(in: 100...499) }
    let mutations = demand.enumerated().map { index, value in
        return value > supply[index] ? value - supply[index] : 0
    }
    return mutations
}

func main() {
    let data = Array(0..<10)
    let result = optimize_supply_chain(data)
    print(result)
}

main()