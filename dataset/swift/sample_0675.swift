func calculateAltitude(target: Int, current: Int, step: Int, precision: Int) -> Int {
    if abs(target - current) < precision {
        return current
    } else {
        return calculateAltitude(target: target, current: current + step, step: step, precision: precision)
    }
}

func main() {
    let a = calculateAltitude(target: 35000, current: 0, step: 1000, precision: 100)
    print(a)
}

main()