import Foundation

func optimize_routes(data: [[Int]]) -> [Int] {
    let costs = data
    var optimalIndices = [Int]()
    for i in 0..<costs[0].count {
        var minIndex = 0
        for j in 1..<costs.count {
            if costs[j][i] < costs[minIndex][i] {
                minIndex = j
            }
        }
        optimalIndices.append(minIndex)
    }
    return optimalIndices
}

func update_inventory(routes: [Int], inventory: [Int]) -> [Int] {
    var updatedInventory = inventory
    for route in routes {
        updatedInventory[route] -= 1
    }
    return updatedInventory
}

func main() {
    let data = [[5, 3, 8], [2, 6, 4], [7, 1, 9]]
    let inventory = [10, 10, 10]
    let routes = optimize_routes(data: data)
    let updatedInventory = update_inventory(routes: routes, inventory: inventory)
    print(updatedInventory)
}

main()