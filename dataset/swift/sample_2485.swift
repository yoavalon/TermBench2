func sequence(x: Int, y: Int) {
    if x > y {
        return
    }
    print(x)
    sequence(x: x + 1, y: y)
}

sequence(x: 1, y: 10)