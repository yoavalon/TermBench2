import Foundation

func transform_coordinates(x: Double, y: Double, z: Double, angle_x: Double, angle_y: Double, angle_z: Double) -> (Double, Double, Double) {
    let rad_x = angle_x * .pi / 180
    let rad_y = angle_y * .pi / 180
    let rad_z = angle_z * .pi / 180
    let cos_x = cos(rad_x)
    let sin_x = sin(rad_x)
    let cos_y = cos(rad_y)
    let sin_y = sin(rad_y)
    let cos_z = cos(rad_z)
    let sin_z = sin(rad_z)
    let x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    let y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    let z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x1, y1, z1)
}

func main() {
    let x = 1.0
    let y = 2.0
    let z = 3.0
    let angle_x = 45.0
    let angle_y = 30.0
    let angle_z = 60.0
    let (x1, y1, z1) = transform_coordinates(x: x, y: y, z: z, angle_x: angle_x, angle_y: angle_y, angle_z: angle_z)
    print("\(x1) \(y1) \(z1)")
}

main()