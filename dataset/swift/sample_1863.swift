import Foundation

func monte_carlo_option_pricing(s: Double, x: Double, t: Double, r: Double, v: Double, n: Int) -> Double {
    let dt = t / Double(n)
    var st = [Double](repeating: 0.0, count: n + 1)
    st[0] = s
    for i in 1...n {
        st[i] = st[i - 1] * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * Double.random(in: -1...1))
    }
    return exp(-r * t) * st.map { max($0 - x, 0) }.reduce(0, +) / Double(n + 1)
}

monte_carlo_option_pricing(s: 100, x: 100, t: 1, r: 0.05, v: 0.2, n: 1000)