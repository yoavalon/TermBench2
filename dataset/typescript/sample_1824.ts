function verify_consensus(a: number, b: number, tolerance: number): boolean {
    let result = Math.abs(a - b) <= tolerance;
    return result;
}

let a = 0.1 + 0.2;
let b = 0.3;
let tolerance = 1e-10;
let main = verify_consensus(a, b, tolerance);
console.log(main);