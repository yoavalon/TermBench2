func transform_point(x: Int, y: Int, z: Int, depth: Int) -> (Int, Int, Int) {
    if depth == 0 {
        return (x, y, z)
    } else {
        return transform_point(x: x + 1, y: y - 1, z: z * 2, depth: depth - 1)
    }
}

func main() {
    let result = transform_point(x: 0, y: 0, z: 0, depth: 5)
    print(result)
}

main()