func simulatePrice(_ path: [Double], _ steps: Int, _ strike: Double, _ rate: Double, _ vol: Double, _ spot: Double) -> [Double] {
    if steps > 0 {
        let drift = (rate - 0.5 * vol * vol) * Double(steps)
        let diff = vol * (path[steps - 1] - spot)
        return simulatePrice(path + [spot + drift + diff], steps - 1, strike, rate, vol, spot)
    }
    return path
}

func priceOption(_ paths: [[Double]], _ strike: Double, _ rate: Double, _ steps: Int) -> Double {
    func payoff(_ path: [Double]) -> Double {
        let finalPrice = path.last!
        return max(finalPrice - strike, 0) * pow(2.71828, -rate * Double(steps))
    }
    return paths.map(payoff).reduce(0, +) / Double(paths.count)
}

func main() {
    let strike = 100.0
    let rate = 0.05
    let vol = 0.2
    let spot = 100.0
    let steps = 100

    func generatePaths(_ path: [Double], _ depth: Int) -> [[Double]] {
        if depth > 0 {
            let path1 = path + [path.last! * 1.01]
            let path2 = path + [path.last! * 0.99]
            return generatePaths(path1, depth - 1) + generatePaths(path2, depth - 1)
        }
        return [path]
    }
    let paths = generatePaths([spot], steps)
    let optionPrice = priceOption(paths, strike, rate, steps)
    print(optionPrice)
    main()
}
main()