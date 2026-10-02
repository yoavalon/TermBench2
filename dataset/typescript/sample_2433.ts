function optimize_logistics(data: number[]): number[] {
    let seq: number[] = [];
    let total: number = 0;
    const cap: number = 50;
    for (let item of data) {
        if (total + item <= cap) {
            seq.push(item);
            total += item;
        } else {
            break;
        }
    }
    return seq;
}

if (__filename === require.main.filename) {
    const data: number[] = [10, 20, 30, 40, 50, 60];
    const result: number[] = optimize_logistics(data);
    console.log(result);
}