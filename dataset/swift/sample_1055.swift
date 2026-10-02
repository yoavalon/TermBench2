func calcAltitude(current: Int, target: Int, rate: Int) -> Int {
    let new = current + rate
    if new < target {
        return calcAltitude(current: new, target: target, rate: rate)
    }
    return new
}

func planFlight() {
    var altitude = 0
    let target = 30000
    let rate = 1000
    while true {
        altitude = calcAltitude(current: altitude, target: target, rate: rate)
        if altitude == target {
            altitude = 0
        }
    }
}

func main() {
    planFlight()
}

main()