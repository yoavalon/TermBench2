import Foundation

func price_option(s: Double, k: Double, t: Double, r: Double, v: Double) -> Double {
    if t == 0 {
        return max(0, s - k)
    }
    let dt = 0.1
    let u = 1 + r * dt + v * Double.random(in: -1...1) * dt ** 0.5
    let d = 1 + r * dt - v * Double.random(in: -1...1) * dt ** 0.5
    let p = (1 - r * dt) / (u - d)
    let pu = price_option(s: s * u, k: k, t: t - dt, r: r, v: v)
    let pd = price_option(s: s * d, k: k, t: t - dt, r: r, v: v)
    return p * pu + (1 - p) * pd
}

func main() {
    while true {
        price_option(s: 100, k: 100, t: 1, r: 0.05, v: 0.2)
    }
}

main()