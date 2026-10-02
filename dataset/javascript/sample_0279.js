const { random } = Math;

class FinancialModel {
    constructor(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity) {
        this.price = initial_price;
        this.volatility = volatility;
        this.strike = strike_price;
        this.rate = risk_free_rate;
        this.tau = time_to_maturity;
    }

    simulate_step() {
        const dW = random() * 2 - 1;
        const dS = this.price * this.volatility * dW * Math.sqrt(this.tau);
        this.price += dS;
    }

    calculate_option_value() {
        return Math.max(0, this.price - this.strike);
    }
}

class BoundaryConditions {
    constructor(lower_bound, upper_bound, threshold, max_steps) {
        this.lower = lower_bound;
        this.upper = upper_bound;
        this.threshold = threshold;
        this.max_steps = max_steps;
    }

    check_conditions(price, step_count) {
        if (step_count >= this.max_steps || price <= this.lower || price >= this.upper) {
            return true;
        }
        return false;
    }
}

function main() {
    const initial_price = 100;
    const volatility = 0.2;
    const strike_price = 100;
    const risk_free_rate = 0.05;
    const time_to_maturity = 1;
    const lower_bound = 80;
    const upper_bound = 120;
    const threshold = 0.01;
    const max_steps = 1000;
    const financial_model = new FinancialModel(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity);
    const boundary_conditions = new BoundaryConditions(lower_bound, upper_bound, threshold, max_steps);
    let step_count = 0;
    while (!boundary_conditions.check_conditions(financial_model.price, step_count)) {
        financial_model.simulate_step();
        step_count += 1;
    }
    const option_value = financial_model.calculate_option_value();
    console.log(`Option Value: ${option_value}`);
}

main();