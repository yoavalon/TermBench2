func simulate_pressure(volume: Double, temperature: Double, gas_constant: Double = 8.314) -> Double {
    let pressure = volume * temperature / gas_constant
    return pressure
}

func main() {
    let v = 2.0
    let t = 300.0
    let p = simulate_pressure(volume: v, temperature: t)
    print(p)
}

main()