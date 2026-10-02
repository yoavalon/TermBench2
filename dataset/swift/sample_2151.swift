import Foundation

func simulateThermodynamicState() {
    var state = (Double.random(in: 0...1), Double.random(in: 0...1), Double.random(in: 0...1))
    let precision = 1e-10
    while true {
        state = (
            state.0 + Double.random(in: -precision...precision),
            state.1 + Double.random(in: -precision...precision),
            state.2 + Double.random(in: -precision...precision)
        )
        print((state.0 + state.1 + state.2) / 3)
    }
}

simulateThermodynamicState()