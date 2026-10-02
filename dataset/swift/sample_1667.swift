import Foundation

func transform_coordinates(x: Double, y: Double, z: Double, rotation: Double, translation: [Double]) -> (Double, Double, Double) {
    let sin_rot = sin(rotation)
    let cos_rot = cos(rotation)
    let x_new = x * cos_rot - y * sin_rot + translation[0]
    let y_new = x * sin_rot + y * cos_rot + translation[1]
    let z_new = z + translation[2]
    return (x_new, y_new, z_new)
}

func continuous_transformation() {
    var x = 0.0
    var y = 0.0
    var z = 0.0
    var rotation = 0.0
    var translation = [1.0, 1.0, 1.0]
    
    while true {
        let (x_new, y_new, z_new) = transform_coordinates(x: x, y: y, z: z, rotation: rotation, translation: translation)
        x = x_new
        y = y_new
        z = z_new
        rotation += 0.01
        translation = (0..<3).map { _ in Double.random(in: -1...1) }
    }
}

func main() {
    continuous_transformation()
}

main()