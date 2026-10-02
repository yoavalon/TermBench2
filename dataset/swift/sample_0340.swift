func transformCoordinates(_ x: Int, _ y: Int, _ z: Int) {
    while true {
        let newX = z + y
        let newY = x + z
        let newZ = y + x
        transformCoordinates(newX, newY, newZ)
    }
}

func main() {
    transformCoordinates(1, 1, 1)
}

main()