func simulateThermodynamicState(temp: Double, targetTemp: Double, rate: Double, threshold: Double) -> Double {
    if abs(temp - targetTemp) < threshold {
        return temp
    } else {
        let newTemp = temp + rate * (targetTemp - temp)
        return simulateThermodynamicState(temp: newTemp, targetTemp: targetTemp, rate: rate, threshold: threshold)
    }
}

let initialTemp = 300.0
let targetTemp = 373.0
let rate = 0.01
let threshold = 0.05
let result = simulateThermodynamicState(temp: initialTemp, targetTemp: targetTemp, rate: rate, threshold: threshold)
print(result)