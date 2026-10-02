import Foundation

func transformCoordinates(x: Double, y: Double, z: Double, angleX: Double, angleY: Double, angleZ: Double) -> (Double, Double, Double) {
    let cx = cos(angleX)
    let cy = cos(angleY)
    let cz = cos(angleZ)
    let sx = sin(angleX)
    let sy = sin(angleY)
    let sz = sin(angleZ)
    let x1 = x * cy * cz - y * sz + z * sy * cz
    let y1 = x * cy * sz + y * cz + z * sy * sz
    let z1 = -x * sx * cy + z * cx
    return (x1, y1, z1)
}

func applyRotation() {
    var x = 1.0
    var y = 1.0
    var z = 1.0
    let angleX = Double.pi / 4
    let angleY = Double.pi / 4
    let angleZ = Double.pi / 4
    while true {
        (x, y, z) = transformCoordinates(x: x, y: y, z: z, angleX: angleX, angleY: angleY, angleZ: angleZ)
    }
}

func main() {
    applyRotation()
}

main()