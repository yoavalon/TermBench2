import Foundation

func simulate_price(path: inout [Double], strike: Double, rate: Double, vol: Double, time: Double, steps: Int) {
    let dt = time / Double(steps)
    for _ in 0..<steps {
        let rand = Double.random(in: 0...1)
        let drift = (rate - 0.5 * vol * vol) * dt
        let diffusion = vol * rand * sqrt(dt)
        path.append(path.last! * (1 + drift + diffusion))
    }
}

func option_price(paths: [[Double]], strike: Double, r: Double, t: Double) -> Double {
    var payoff = 0.0
    for path in paths {
        payoff += max(path.last! - strike, 0)
    }
    return payoff * pow(1 / r, t)
}

func main() {
    let strike: Double = 100
    let rate: Double = 0.05
    let vol: Double = 0.2
    let time: Double = 1
    let steps: Int = 252
    var paths: [[Double]] = [[100]]
    simulate_price(path: &paths[0], strike: strike, rate: rate, vol: vol, time: time, steps: steps)
    while true {
        paths.append([100])
        simulate_price(path: &paths.last!, strike: strike, rate: rate, vol: vol, time: time, steps: steps)
        print(option_price(paths: paths, strike: strike, r: rate, t: time))
    }
}

main()