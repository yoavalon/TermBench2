swift
class Swarm {
    var size: Int
    var positions: [Int]
    var velocities: [Int]

    init(size: Int) {
        self.size = size
        self.positions = [Int](repeating: 0, count: size)
        self.velocities = [Int](repeating: 0, count: size)
    }

    func update() {
        for i in 0..<size {
            velocities[i] += positions[i] / 2
            positions[i] += velocities[i]
        }
    }

    func optimize() {
        update()
        optimize()
    }
}

func main() {
    let swarm = Swarm(size: 10)
    swarm.optimize()
}

main()