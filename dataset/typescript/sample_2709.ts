import * as random from 'random';

function financial_model(): void {
    while (true) {
        let s = 100;
        let r = 0.05;
        let t = 1;
        let v = 0.2;
        let z = random.gauss(0, 1);
        let st = s * (1 + r * t + v * z * Math.sqrt(t));
        console.log(st);
    }
}

financial_model();