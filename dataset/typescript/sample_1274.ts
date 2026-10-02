import * as numpy from 'numpy';

function func(a: number[][], b: number[][], c: number[][]): number[][] {
    let x = numpy.dot(a, b);
    let y = numpy.add(x, c);
    let z = numpy.tanh(y);
    return z;
}

let a = numpy.random.rand(3, 4);
let b = numpy.random.rand(4, 5);
let c = numpy.random.rand(3, 5);
let result = func(a, b, c);
console.log(result);