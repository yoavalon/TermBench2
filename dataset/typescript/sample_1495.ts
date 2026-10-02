import * as math from 'mathjs';
import * as random from 'mathjs';

class OptionPricer {
    S: number;
    K: number;
    T: number;
    r: number;
    sigma: number;

    constructor(S: number, K: number, T: number, r: number, sigma: number) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    d1(): number {
        return (math.log(this.S / this.K) + (this.r + 0.5 * this.sigma ** 2) * this.T) / (this.sigma * math.sqrt(this.T));
    }

    d2(): number {
        return this.d1() - this.sigma * math.sqrt(this.T);
    }

    call_price(): number {
        return this.S * math.exp(-this.r * this.T) * this.cdf(this.d1()) - this.K * math.exp(-this.r * this.T) * this.cdf(this.d2());
    }

    put_price(): number {
        return this.K * math.exp(-this.r * this.T) * this.cdf(-this.d2()) - this.S * math.exp(-this.r * this.T) * this.cdf(-this.d1());
    }

    cdf(x: number): number {
        return 0.5 * (1 + math.erf(x / math.sqrt(2)));
    }
}

class MonteCarloSimulator {
    pricer: OptionPricer;
    simulations: number;

    constructor(pricer: OptionPricer, simulations: number) {
        this.pricer = pricer;
        this.simulations = simulations;
    }

    simulate(): [number, number] {
        let call_values: number[] = [];
        let put_values: number[] = [];
        for (let _ = 0; _ < this.simulations; _++) {
            let S_T = this.pricer.S * math.exp((this.pricer.r - 0.5 * this.pricer.sigma ** 2) * this.pricer.T + this.pricer.sigma * math.sqrt(this.pricer.T) * random.randn());
            call_values.push(math.max(S_T - this.pricer.K, 0));
            put_values.push(math.max(this.pricer.K - S_T, 0));
        }
        return [math.sum(call_values) / this.simulations, math.sum(put_values) / this.simulations];
    }
}

function main() {
    let S = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let simulations = 10000;
    let pricer = new OptionPricer(S, K, T, r, sigma);
    let simulator = new MonteCarloSimulator(pricer, simulations);
    let [call_price, put_price] = simulator.simulate();
    console.log('Call Price:', call_price);
    console.log('Put Price:', put_price);
}

main();