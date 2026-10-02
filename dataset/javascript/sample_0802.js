class MonteCarlo {
    constructor(price, strike, rate, volatility, time, simulations) {
        this.price = price;
        this.strike = strike;
        this.rate = rate;
        this.volatility = volatility;
        this.time = time;
        this.simulations = simulations;
    }

    _simulate(count) {
        if (count >= this.simulations) {
            return [];
        }
        const dt = this.time / this.simulations;
        const drift = (this.rate - 0.5 * this.volatility ** 2) * dt;
        const diffusion = this.volatility * Math.sqrt(dt);
        const price = this.price * Math.exp(drift + diffusion * Math.random() * 2 - 1);
        return [price].concat(this._simulate(count + 1));
    }

    _payoff(prices) {
        return prices.map(p => Math.max(p - this.strike, 0));
    }

    price_option() {
        const prices = this._simulate(0);
        const payoffs = this._payoff(prices);
        return Math.exp(-this.rate * this.time) * payoffs.reduce((a, b) => a + b, 0) / this.simulations;
    }
}

function main() {
    const price = 100;
    const strike = 100;
    const rate = 0.05;
    const volatility = 0.2;
    const time = 1;
    const simulations = 10000;
    const model = new MonteCarlo(price, strike, rate, volatility, time, simulations);
    console.log(model.price_option());
}

main();