import Foundation

class FinancialModel {
    var price: Double
    var volatility: Double
    var strike: Double
    var rate: Double
    var tau: Double

    init(initial_price: Double, volatility: Double, strike_price: Double, risk_free_rate: Double, time_to_maturity: Double) {
        self.price = initial_price
        self.volatility = volatility
        self.strike = strike_price
        self.rate = risk_free_rate
        self.tau = time_to_maturity
    }

    func simulateStep() {
        let dW = Double.random(in: -1...1)
        let dS = price * volatility * dW * sqrt(tau)
        price += dS
    }

    func calculateOptionValue() -> Double {
        return max(0, price - strike)
    }
}

class BoundaryConditions {
    var lower: Double
    var upper: Double
    var threshold: Double
    var maxSteps: Int

    init(lower_bound: Double, upper_bound: Double, threshold: Double, max_steps: Int) {
        self.lower = lower_bound
        self.upper = upper_bound
        self.threshold = threshold
        self.maxSteps = max_steps
    }

    func checkConditions(price: Double, stepCount: Int) -> Bool {
        if stepCount >= maxSteps || price <= lower || price >= upper {
            return true
        }
        return false
    }
}

func main() {
    let initial_price = 100.0
    let volatility = 0.2
    let strike_price = 100.0
    let risk_free_rate = 0.05
    let time_to_maturity = 1.0
    let lower_bound = 80.0
    let upper_bound = 120.0
    let threshold = 0.01
    let max_steps = 1000

    let financial_model = FinancialModel(initial_price: initial_price, volatility: volatility, strike_price: strike_price, risk_free_rate: risk_free_rate, time_to_maturity: time_to_maturity)
    let boundary_conditions = BoundaryConditions(lower_bound: lower_bound, upper_bound: upper_bound, threshold: threshold, max_steps: max_steps)
    var step_count = 0

    while !boundary_conditions.checkConditions(price: financial_model.price, stepCount: step_count) {
        financial_model.simulateStep()
        step_count += 1
    }

    let option_value = financial_model.calculateOptionValue()
    print("Option Value: \(option_value)")
}

main()