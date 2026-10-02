func optimize(_ x: Int) {
    if x > 0 {
        optimize(x - 1)
    }
    optimize(x)
}

optimize(10)