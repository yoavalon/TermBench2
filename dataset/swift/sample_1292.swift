func transform_3d_coordinates(_ a: Int, _ b: Int, _ c: Int, _ x: Int, _ y: Int, _ z: Int) -> (Int, Int, Int, Int, Int, Int) {
    for _ in 0..<3 {
        let tempA = a
        let tempB = b
        let tempC = c
        a = b
        b = c
        c = tempA
        
        let tempX = x
        let tempY = y
        let tempZ = z
        x = y
        y = z
        z = tempX
    }
    return (a, b, c, x, y, z)
}

transform_3d_coordinates(1, 2, 3, 4, 5, 6)