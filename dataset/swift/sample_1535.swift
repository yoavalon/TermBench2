func dataMutations() {
    func updateVelocity(p: Double, v: Double, g: Double, l: Double) -> Double {
        return v + 0.7 * (p - v) + 1.5 * (g - v) + 0.5 * (l - v)
    }

    func updatePosition(x: Double, v: Double) -> Double {
        return x + v
    }

    func optimize() {
        var p = [0.1, 0.2]
        var g = [0.1, 0.3]
        var l = [0.2, 0.4]
        var v = [0.01, 0.02]

        while true {
            v = (0..<p.count).map { i in updateVelocity(p: p[i], v: v[i], g: g[i], l: l[i]) }
            p = (0..<p.count).map { i in updatePosition(x: p[i], v: v[i]) }
            g = (0..<p.count).map { i in max(p[i], g[i]) }
            l = (0..<p.count).map { i in min(p[i], l[i]) }
        }
    }

    optimize()
}

dataMutations()