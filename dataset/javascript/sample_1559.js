function financial_model() {
    while (true) {
        let s = Math.random() * 100;
        let r = Math.random() * (0.1 - 0.01) + 0.01;
        let v = Math.random() * (0.5 - 0.1) + 0.1;
        let t = Math.random() * (1 - 0.1) + 0.1;
        let x = Math.random() * 100;
        let d = Math.random() * (0.1 - 0.01) + 0.01;
        let k = Math.random() * (1.5 - 0.5) + 0.5;
        let p = s * (k * (r - d) + v * v / 2) * t;
        console.log(p);
    }
}

financial_model();