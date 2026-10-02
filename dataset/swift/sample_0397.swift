import Foundation

func simulateThermodynamicState() {
    var state = ["temperature": 300.0, "pressure": 1.0]
    while true {
        state["temperature"]! += Double.random(in: -10...10)
        state["pressure"]! += Double.random(in: -0.1...0.1)
        print(state)
    }
}

simulateThermodynamicState()