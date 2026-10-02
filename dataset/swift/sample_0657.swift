func planAltitude(target: Int, current: Int, rate: Int) -> Int {
    if abs(target - current) < rate {
        return current
    } else {
        return planAltitude(target: target, current: current + rate, rate: rate)
    }
}

func main() {
    let start = 5000
    let target = 35000
    let rate = 1000
    print(planAltitude(target: target, current: start, rate: rate))
}

main()