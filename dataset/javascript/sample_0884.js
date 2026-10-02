class OptionPricer {
    constructor(strike, spot, vol, rate, div, T) {
        this.strike = strike;
        this.spot = spot;
        this.vol = vol;
        this.rate = rate;
        this.div = div;
        this.T = T;
    }

    d1(S, K, T, r, q, sigma) {
        return (Math.log(S / K) + (r - q + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T));
    }

    d2(d1, sigma, T) {
        return d1 - sigma * Math.sqrt(T);
    }

    call_price(S, K, T, r, q, sigma) {
        if (T <= 0) {
            return Math.max(0, S - K);
        }
        let d1_val = this.d1(S, K, T, r, q, sigma);
        let d2_val = this.d2(d1_val, sigma, T);
        return S * Math.exp(-q * T) * norm.cdf(d1_val) - K * Math.exp(-r * T) * norm.cdf(d2_val);
    }
}

class MonteCarloSimulator {
    constructor(pricer, paths, steps) {
        this.pricer = pricer;
        this.paths = paths;
        this.steps = steps;
    }

    simulate() {
        let prices = [];
        for (let i = 0; i < this.paths; i++) {
            let price_path = this.pricer.spot;
            for (let j = 1; j < this.steps; j++) {
                price_path = this._step(price_path);
            }
            prices.push(price_path);
        }
        return prices;
    }

    _step(S) {
        let dt = this.pricer.T / this.steps;
        let dS = S * (this.pricer.rate - this.pricer.div) * dt + S * this.pricer.vol * Math.sqrt(dt) * Math.random();
        return S + dS;
    }
}

function main() {
    let strike = 100;
    let spot = 100;
    let vol = 0.2;
    let rate = 0.05;
    let div = 0.02;
    let T = 1;
    let paths = 1000;
    let steps = 100;
    let pricer = new OptionPricer(strike, spot, vol, rate, div, T);
    let simulator = new MonteCarloSimulator(pricer, paths, steps);
    let final_prices = simulator.simulate();
    let option_value = final_prices.reduce((sum, price) => sum + pricer.call_price(price, strike, T, rate, div, vol), 0) / paths;
    console.log(option_value);
}

main();