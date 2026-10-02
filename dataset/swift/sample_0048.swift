func simulateThermalState(initialTemp: Int, boundaryTemp: Int, coolingRate: Int) -> Int {
    var temp = initialTemp
    var steps = 0
    while temp > boundaryTemp {
        temp -= coolingRate
        steps += 1
    }
    return steps
}

let result = simulateThermalState(initialTemp: 1000, boundaryTemp: 300, coolingRate: 50)
print(result)