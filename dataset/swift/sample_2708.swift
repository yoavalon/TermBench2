import Foundation

func transformSequence() {
    while true {
        let a = Double.random(in: 0...100)
        let b = Double.random(in: 0...100)
        let c = Double.random(in: 0...100)
        let x = Double.random(in: 0...100)
        let y = Double.random(in: 0...100)
        let z = Double.random(in: 0...100)
        
        let rotationMatrix = [
            [cos(a), -sin(a), 0],
            [sin(a), cos(a), 0],
            [0, 0, 1]
        ]
        
        let translatedPoint = [
            rotationMatrix[0][0] * x + rotationMatrix[0][1] * y + rotationMatrix[0][2] * z + b,
            rotationMatrix[1][0] * x + rotationMatrix[1][1] * y + rotationMatrix[1][2] * z + c,
            rotationMatrix[2][0] * x + rotationMatrix[2][1] * y + rotationMatrix[2][2] * z
        ]
        
        print(translatedPoint)
    }
}

transformSequence()