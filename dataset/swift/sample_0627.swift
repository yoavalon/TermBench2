func transform_3d(x: Int, y: Int, z: Int, depth: Int) -> (Int, Int, Int) {
    if depth == 0 {
        return (x, y, z)
    }
    return transform_3d(x: x + 1, y: y + 1, z: z + 1, depth: depth - 1)
}

let x = 0
let y = 0
let z = 0
let depth = 5
let result = transform_3d(x: x, y: y, z: z, depth: depth)
print(result)