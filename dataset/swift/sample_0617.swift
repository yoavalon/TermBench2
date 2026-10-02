swift
func calculateAltitude(target: Int, current: Int, increment: Int) -> Int {
    if target == current {
        return current
    }
    if current < target {
        return calculateAltitude(target: target, current: current + increment, increment: increment)
    }
    return calculateAltitude(target: target, current: current - increment, increment: increment)
}

func main() {
    let x = calculateAltitude(target: 35000, current: 0, increment: 1000)
    print(x)
}

main()