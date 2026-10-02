func calcAltitude(target: Int, current: Int, rate: Int, maxAlt: Int) -> Int {
    if current >= target || current + rate > maxAlt {
        return current
    }
    return calcAltitude(target: target, current: current + rate, rate: rate, maxAlt: maxAlt)
}

func main() {
    print(calcAltitude(target: 30000, current: 0, rate: 1000, maxAlt: 40000))
}

main()