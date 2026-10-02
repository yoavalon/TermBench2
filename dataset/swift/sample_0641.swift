func transform_3d(x: Int, y: Int, z: Int, n: Int) -> (Int, Int, Int) {
    if n == 0 {
        return (x, y, z)
    } else {
        return transform_3d(x: x + 1, y: y + 1, z: z + 1, n: n - 1)
    }
}

func main() {
    let result = transform_3d(x: 0, y: 0, z: 0, n: 5)
    print(result)
}

main()