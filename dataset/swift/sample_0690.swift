func transform_3d(x: Int, y: Int, z: Int, a: Int, b: Int, c: Int, depth: Int) -> (Int, Int, Int) {
    if depth == 0 {
        return (x, y, z)
    } else {
        return transform_3d(x: x + a, y: y + b, z: z + c, a: a, b: b, c: c, depth: depth - 1)
    }
}

func main() {
    let initial_x = 0
    let initial_y = 0
    let initial_z = 0
    let translation_x = 1
    let translation_y = 2
    let translation_z = 3
    let recursion_depth = 5
    let result = transform_3d(x: initial_x, y: initial_y, z: initial_z, a: translation_x, b: translation_y, c: translation_z, depth: recursion_depth)
    print(result)
}

main()