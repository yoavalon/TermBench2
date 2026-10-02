func optimize_supply_chain(_ cost: [Int], _ index: Int, _ path: inout [Int]) -> [Int] {
    path.append(index)
    if cost[index] == 0 {
        return path
    }
    let next_index = cost[index] - 1
    return optimize_supply_chain(cost, next_index, &path)
}

func main() {
    var cost = [3, 2, 4, 1, 0, 5]
    var path = [Int]()
    let result = optimize_supply_chain(cost, 0, &path)
    print(result)
}

main()