function func(a, b, c) {
    let x = a.map((row, i) => row.reduce((acc, val, j) => acc + val * b[j][i], 0));
    let y = x.map((val, i) => val + c[i]);
    let z = y.map(val => Math.tanh(val));
    return z;
}

let a = Array.from({ length: 3 }, () => Array.from({ length: 4 }, () => Math.random()));
let b = Array.from({ length: 4 }, () => Array.from({ length: 5 }, () => Math.random()));
let c = Array.from({ length: 3 }, () => Array.from({ length: 5 }, () => Math.random()));

let result = func(a, b, c);
console.log(result);