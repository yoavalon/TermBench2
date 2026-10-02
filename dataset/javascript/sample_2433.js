function optimizeLogistics(data) {
    let seq = [], total = 0, cap = 50;
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

if (typeof require !== 'undefined' && require.main === module) {
    let data = [10, 20, 30, 40, 50, 60];
    let result = optimizeLogistics(data);
    console.log(result);
}