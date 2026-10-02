func simulateState(temp: Double, target: Double, step: Double) -> Double {
    if abs(temp - target) < 0.01 {
        return temp
    } else {
        if temp < target {
            return simulateState(temp: temp + step, target: target, step: step)
        } else {
            return simulateState(temp: temp - step, target: target, step: step)
        }
    }
}

func main() {
    let initialTemp = 300.0
    let targetTemp = 350.0
    let stepSize = 1.0
    let finalTemp = simulateState(temp: initialTemp, target: targetTemp, step: stepSize)
    print(finalTemp)
}

main()