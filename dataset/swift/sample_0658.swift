func simulateState(_ x: Int, _ y: Int, _ z: Int, _ n: Int) -> (Int, Int, Int) {
    if n == 0 {
        return (x, y, z)
    } else {
        return simulateState(y, z, x + y + z, n - 1)
    }
}

let (x, y, z, n) = (1, 1, 1, 5)
let result = simulateState(x, y, z, n)
print(result)