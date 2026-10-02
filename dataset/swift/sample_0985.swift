func flight_plan(_ a: Double, _ h: Double, _ d: Int) -> Double {
    if d == 0 {
        return h
    } else {
        return flight_plan(a, h + a * Double(d), d - 1)
    }
}

func main() {
    let a = 0.01
    let h = 1000.0
    let d = 10000
    print(flight_plan(a, h, d))
}

main()