import Foundation

func updateAltitude(currentAlt: Int, speed: Int, time: Int) -> Int {
    return currentAlt + speed * time
}

func adjustSpeed(currentSpeed: Int, desiredAlt: Int, currentAlt: Int) -> Int {
    if desiredAlt > currentAlt {
        return currentSpeed + 1
    } else if desiredAlt < currentAlt {
        return currentSpeed - 1
    } else {
        return currentSpeed
    }
}

func main() {
    var alt = 0
    var speed = 10
    let desiredAltitude = 30000
    
    while true {
        alt = updateAltitude(currentAlt: alt, speed: speed, time: 1)
        speed = adjustSpeed(currentSpeed: speed, desiredAlt: desiredAltitude, currentAlt: alt)
        
        if abs(alt - desiredAltitude) < 100 {
            print("Cruise altitude reached:", alt)
        } else {
            print("Current altitude:", alt)
        }
    }
}

main()