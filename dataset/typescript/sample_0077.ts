const { random } = require('mathjs');

function matrix_op(x: number[][], w: number[][], b: number[][]): number[][] {
    const z = math.add(math.dot(x, w), b);
    const a = math.max(0, z);
    return a;
}

if (require.main === module) {
    const x = math.random([3, 4]);
    const w = math.random([4, 5]);
    const b = math.random([1, 5]);
    const result = matrix_op(x, w, b);
    console.log(result);
}