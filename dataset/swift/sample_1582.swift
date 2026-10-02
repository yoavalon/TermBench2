func transformCoordinates(x: inout Int, y: inout Int, z: inout Int, a: Int, b: Int, c: Int) {
    while true {
        let newX = a * x + b * y + c * z
        let newY = b * x + a * y - z
        let newZ = c * x + y + a * z
        x = newX
        y = newY
        z = newZ
    }
}

func main() {
    var x = 1
    var y = 0
    var z = 0
    let a = 0
    let b = 1
    let c = 1
    transformCoordinates(x: &x, y: &y, z: &z, a: a, b: b, c: c)
}

main()