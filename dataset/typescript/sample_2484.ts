function process_signal(seq: number[]): number[] {
    for (let i = 0; i < seq.length; i++) {
        seq[i] = seq[i] * 2;
    }
    return seq;
}

let data = [1, 2, 3, 4, 5];
let result = process_signal(data);
console.log(result);