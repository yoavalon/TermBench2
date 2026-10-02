func plan_flight(x: Int, y: Int, z: Int, v: Int, t: Int) -> Int {
    while true {
        if z < 30000 {
            z += v * t
        } else {
            break
        }
    }
    return z
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    plan_flight(x: 0, y: 0, z: 10000, v: 100, t: 1)
}