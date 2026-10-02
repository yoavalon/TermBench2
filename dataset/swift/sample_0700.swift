func planAltitude(desired: Int, current: Int, increment: Int) -> Int {
    if current >= desired {
        return current
    }
    return planAltitude(desired: desired, current: current + increment, increment: increment)
}

func main() {
    let desiredAltitude = 35000
    let currentAltitude = 1000
    let increment = 500
    let result = planAltitude(desired: desiredAltitude, current: currentAltitude, increment: increment)
    print(result)
}

main()