func calculateAltitude(t: Double, v: Double, g: Double, h0: Double) -> Double {
    let a = g * t
    let h = h0 - 0.5 * a
    return h
}

func main() {
    let t = 10.0
    let v = 200.0
    let g = 9.81
    let h0 = 35000.0
    let h = calculateAltitude(t: t, v: v, g: g, h0: h0)
    print(h)
}

main()