const math = require('mathjs');
const random = require('mathjs').random;

class OptionPricer {
    constructor(S, K, T, r, sigma) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    d1() {
        return (math.log(this.S / this.K) + (this.r + 0.5 * this.sigma ** 2) * this.T) / (this.sigma * math.sqrt(this.T));
    }

    d2() {
        return this.d1() - this.sigma * math.sqrt(this.T);
    }

    call_price() {
        return this.S * math.exp(-this.r * this.T) * this.cdf(this.d1()) - this.K * math.exp(-this.r * this.T) * this.cdf(this.d2());
    }

    put_price() {
        return this.K * math.exp(-this.r * this.T) * this.cdf(-this.d2()) - this.S * math.exp(-this.r * this.T) * this.cdf(-this.d1());
    }

    cdf(x) {
        return 0.5 * (1 + math.erf(x / math.sqrt(2)));
    }
}

class MonteCarloSimulator {
    constructor(pricer, simulations) {
        this.pricer = pricer;
        this.simulations = simulations;
    }

    simulate() {
        let call_values = [];
        let put_values = [];
        for (let i = 0; i < this.simulations; i++) {
            let S_T = this.pricer.S * math.exp((this.pricer.r - 0.5 * this.pricer.sigma ** 2) * this.pricer.T + this.pricer.sigma * math.sqrt(this.pricer.T) * random());
            call_values.push(math.max(S_T - this.pricer.K, 0));
            put_values.push(math.max(this.pricer.K - S_T, 0));
        }
        return (sum(call_values) / this.simulations, sum(put_values) / this.simulations);
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