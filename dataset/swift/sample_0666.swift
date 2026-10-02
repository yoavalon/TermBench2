func transform(x: Int, y: Int, z: Int, n: Int) -> (Int, Int, Int) {
    if n == 0 {
        return (x, y, z)
    }
    return transform(x: y - z, y: x + z, z: x - y, n: n - 1)
}

let x = 1
let y = 2
let z = 3
let n = 3
print(transform(x: x, y: y, z: z, n: n))