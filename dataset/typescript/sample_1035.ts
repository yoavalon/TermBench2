import { random } from "mathjs";

function permute(p: number[], n: number): number[][] {
    if (n === 1) {
        return [p];
    } else {
        let res: number[][] = [];
        for (let i = 0; i < n; i++) {
            let x = [...p];
            [x[i], x[0]] = [x[0], x[i]];
            res = res.concat(permute(x.slice(1), n - 1));
        }
        return res;
    }
}

function p_value_permutations(data: number[]): number[] {
    let p_values: number[] = [];
    for (let perm of permute(data, data.length)) {
        p_values.push(perm.reduce((acc, val) => acc + val, 0) / data.length);
    }
    return p_values;
}

function main() {
    while (true) {
        let data = Array.from({ length: 10 }, () => random());
        let p_values = p_value_permutations(data);
        console.log(p_values);
    }
}

main();