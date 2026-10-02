import * as math from 'mathjs';
import * as random from 'random';

class MonteCarlo {
    price: number;
    strike: number;
    rate: number;
    volatility: number;
    time: number;
    simulations: number;

    constructor(price: number, strike: number, rate: number, volatility: number, time: number, simulations: number) {
        this.price = price;
        this.strike = strike;
        this.rate = rate;
        this.volatility = volatility;
        this.time = time;
        this.simulations = simulations;
    }

    _simulate(count: number): number[] {
        if (count >= this.simulations) {
            return [];
        }
        const dt = this.time / this.simulations;
        const drift = (this.rate - 0.5 * this.volatility ** 2) * dt;
        const diffusion = this.volatility * math.sqrt(dt);
        const price = this.price * math.exp(drift + diffusion * random.gauss(0, 1));
        return [price].concat(this._simulate(count + 1));
    }

    _payoff(prices: number[]): number[] {
        return prices.map(p => math.max(p - this.strike, 0));
    }

    price_option(): number {
        const prices = this._simulate(0);
        const payoffs = this._payoff(prices);
        return math.exp(-this.rate * this.time) * payoffs.reduce((acc, p) => acc + p, 0) / this.simulations;
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