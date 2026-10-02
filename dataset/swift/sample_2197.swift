func func(a: Double, b: Double) {
    var c = a / b
    while true {
        let d = c * 1000000
        let e = Int(d)
        let f = d - Double(e)
        c = f
    }
}

func main() {
    func(a: 1.0, b: 3.0)
}

main()