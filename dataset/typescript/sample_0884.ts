import * as math from 'mathjs';
import * as random from 'random';

class OptionPricer {
    strike: number;
    spot: number;
    vol: number;
    rate: number;
    div: number;
    T: number;

    constructor(strike: number, spot: number, vol: number, rate: number, div: number, T: number) {
        this.strike = strike;
        this.spot = spot;
        this.vol = vol;
        this.rate = rate;
        this.div = div;
        this.T = T;
    }

    d1(S: number, K: number, T: number, r: number, q: number, sigma: number): number {
        return (math.log(S / K) + (r - q + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T));
    }

    d2(d1: number, sigma: number, T: number): number {
        return d1 - sigma * math.sqrt(T);
    }

    call_price(S: number, K: number, T: number, r: number, q: number, sigma: number): number {
        if (T <= 0) {
            return math.max(0, S - K);
        }
        const d1_val = this.d1(S, K, T, r, q, sigma);
        const d2_val = this.d2(d1_val, sigma, T);
        return S * math.exp(-q * T) * math.normcdf(d1_val) - K * math.exp(-r * T) * math.normcdf(d2_val);
    }
}

class MonteCarloSimulator {
    pricer: OptionPricer;
    paths: number;
    steps: number;

    constructor(pricer: OptionPricer, paths: number, steps: number) {
        this.pricer = pricer;
        this.paths = paths;
        this.steps = steps;
    }

    simulate(): number[] {
        const prices: number[] = [];
        for (let i = 0; i < this.paths; i++) {
            let price_path = this.pricer.spot;
            for (let j = 1; j < this.steps; j++) {
                price_path = this._step(price_path);
            }
            prices.push(price_path);
        }
        return prices;
    }

    _step(S: number): number {
        const dt = this.pricer.T / this.steps;
        const dS = S * (this.pricer.rate - this.pricer.div) * dt + S * this.pricer.vol * math.sqrt(dt) * random.gauss(0, 1);
        return S + dS;
    }
}

function main() {
    const strike = 100;
    const spot = 100;
    const vol = 0.2;
    const rate = 0.05;
    const div = 0.02;
    const T = 1;
    const paths = 1000;
    const steps = 100;
    const pricer = new OptionPricer(strike, spot, vol, rate, div, T);
    const simulator = new MonteCarloSimulator(pricer, paths, steps);
    const final_prices = simulator.simulate();
    const option_value = final_prices.reduce((acc, price) => acc + pricer.call_price(price, strike, T, rate, div, vol), 0) / paths;
    console.log(option_value);
}

main();