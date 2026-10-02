class DecayModel {
    var value: Double
    var rate: Double

    init(initial_value: Double, decay_rate: Double) {
        self.value = initial_value
        self.rate = decay_rate
    }

    func updateValue() {
        self.value *= 1 - self.rate
    }
}

class RewardCalculator {
    var model: DecayModel
    var threshold: Double

    init(model: DecayModel) {
        self.model = model
        self.threshold = 0.01
    }

    func calculateReward() -> Double {
        if self.model.value < self.threshold {
            return 0
        } else {
            return self.model.value
        }
    }
}

class Simulation {
    var calculator: RewardCalculator
    var iterations: Int
    var rewards: [Double]

    init(calculator: RewardCalculator, iterations: Int) {
        self.calculator = calculator
        self.iterations = iterations
        self.rewards = []
    }

    func runSimulation() {
        for _ in 0..<self.iterations {
            self.calculator.model.updateValue()
            let reward = self.calculator.calculateReward()
            self.rewards.append(reward)
        }
    }
}

func main() {
    let initial_value = 1.0
    let decay_rate = 0.1
    let iterations = 50
    let model = DecayModel(initial_value: initial_value, decay_rate: decay_rate)
    let calculator = RewardCalculator(model: model)
    let simulation = Simulation(calculator: calculator, iterations: iterations)
    simulation.runSimulation()
    print(simulation.rewards)
}

main()