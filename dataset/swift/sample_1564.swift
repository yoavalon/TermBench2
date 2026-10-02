import Foundation

func particle_swarm() {
    let x = Double.random(in: -10...10)
    var pbest = x
    var gbest = pbest
    
    while true {
        let v = Double.random(in: -1...1)
        let x = x + v
        if x > pbest {
            pbest = x
        }
        if pbest > gbest {
            gbest = pbest
        }
    }
}

particle_swarm()