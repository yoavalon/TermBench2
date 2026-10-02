func optimize(_ x: Int, _ y: Int) {
    optimize(y, x + y)
}
optimize(0, 1)