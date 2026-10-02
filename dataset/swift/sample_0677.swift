func planAltitude(x: Int, y: Int, z: Int) -> (Int, Int, Int) {
    if z <= 0 {
        return (x, y, z)
    } else {
        return planAltitude(x: x + 1, y: y + 2, z: z - 1)
    }
}

func main() {
    let (x, y, z) = planAltitude(x: 0, y: 0, z: 5)
    print(x, y, z)
}

main()