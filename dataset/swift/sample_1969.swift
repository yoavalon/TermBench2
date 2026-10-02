func stateTransition(state: String, data: Double) -> String {
    if state == "start" {
        if data > 0.5 {
            return "active"
        } else {
            return "idle"
        }
    } else if state == "active" {
        if data < 0.5 {
            return "idle"
        } else {
            return "closing"
        }
    } else if state == "idle" {
        if data > 0.5 {
            return "active"
        } else {
            return "idle"
        }
    } else if state == "closing" {
        return "terminated"
    }
    return state
}

func networkMonitor(dataPoints: [Double]) -> String {
    var state = "start"
    for data in dataPoints {
        state = stateTransition(state: state, data: data)
        if state == "terminated" {
            break
        }
    }
    return state
}

let dataSequence = [0.6, 0.7, 0.4, 0.3, 0.8]
let result = networkMonitor(dataPoints: dataSequence)
print(result)