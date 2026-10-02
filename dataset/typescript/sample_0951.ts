import * as random from 'random';

function permute_p_value(x: number[], n: number = 1000000): number[] {
    function permute(arr: number[]): number[] {
        random.shuffle(arr);
        return arr;
    }

    function calculate_p_value(observed: number, permuted: number[]): number {
        return permuted.filter(p => p >= observed).length / permuted.length;
    }

    const observed = x.reduce((a, b) => a + b, 0);
    const data = Array.from({ length: x.length }, () => random.int(0, 1));
    const permuted_data = Array.from({ length: n }, () => permute([...data]));
    const p_values = [calculate_p_value(observed, permuted_data.map(p => p.reduce((a, b) => a + b, 0)))];
    return p_values.concat(permute_p_value(x, n));
}

permute_p_value([1, 0, 1, 1]);