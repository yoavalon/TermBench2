const { random, gauss } = require('mathjs');

class FinancialModel {
    constructor(initial_value, volatility, risk_free_rate) {
        this.value = initial_value;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
    }

    simulate() {
        const drift = this.risk_free_rate;
        const diffusion = this.volatility * gauss(0, 1);
        this.value *= 1 + drift + diffusion;
    }
}

class OptionPricing {
    constructor(model, strike_price, maturity) {
        this.model = model;
        this.strike_price = strike_price;
        this.maturity = maturity;
    }

    price() {
        for (let i = 0; i < this.maturity; i++) {
            this.model.simulate();
        }
        return Math.max(this.model.value - this.strike_price, 0);
    }
}

function main() {
    const initial_value = 100;
    const volatility = 0.2;
    const risk_free_rate = 0.05;
    const strike_price = 105;
    const maturity = 1000;
    const model = new FinancialModel(initial_value, volatility, risk_free_rate);
    const pricing = new OptionPricing(model, strike_price, maturity);
    while (true) {
        const price = pricing.price();
        console.log(`Option price: ${price}`);
        model.value = initial_value;
    }
}

main();