func transformPoint(x: Int, y: Int, z: Int) -> (Int, Int, Int) {
    return (z, x, y)
}

func recursiveTransform(x: Int, y: Int, z: Int) {
    let (newX, newY, newZ) = transformPoint(x: x, y: y, z: z)
    recursiveTransform(x: newX, y: newY, z: newZ)
}

recursiveTransform(x: 1, y: 2, z: 3)