import Foundation

func monte_carlo_pricing(s: Double, k: Double, r: Double, v: Double, t: Double, n: Int) -> Double {
    let dt = t / Double(n)
    var st = [Double](repeating: 0.0, count: n + 1)
    st[0] = s
    for i in 1...n {
        st[i] = st[i - 1] * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * Double.random(in: -1...1))
    }
    return exp(-r * t) * st.map { max($0 - k, 0) }.reduce(0, +) / Double(n)
}

monte_carlo_pricing(s: 100, k: 100, r: 0.05, v: 0.2, t: 1, n: 1000)