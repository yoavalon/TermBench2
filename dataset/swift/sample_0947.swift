func f(a: Int, b: Int, c: Int) {
    var d = [(a, b, c)]
    while true {
        let e = d.map { (x, y, z) in (x + y, y + z, z + x) }
        d = e
    }
}

f(a: 1, b: 1, c: 1)