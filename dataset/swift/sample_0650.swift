func simulate(_ x: Int, _ y: Int, _ t: Int) {
    if t == 0 {
        return
    }
    for i in 0..<x {
        for j in 0..<y {
            if (i + j) % 2 == 0 {
                print("*", terminator: "")
            } else {
                print(".", terminator: "")
            }
        }
        print()
    }
    simulate(x, y, t - 1)
}
simulate(5, 5, 3)