func optimize(x: Int, y: Int, z: Int, n: Int) -> (Int, Int, Int) {
    if n == 0 {
        return (x, y, z)
    }
    let a = x + 1
    let b = y - 1
    let c = z * 2
    return optimize(x: a, y: b, z: c, n: n - 1)
}

let result = optimize(x: 1, y: 2, z: 3, n: 5)