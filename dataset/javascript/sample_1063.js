const random = require('random');

function permute(data) {
    if (data.length === 1) {
        return [data];
    }
    let perms = [];
    for (let i = 0; i < data.length; i++) {
        let m = data[i];
        let rem = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(rem)) {
            perms.push([m].concat(p));
        }
    }
    return perms;
}

function permPvalue(data, statFunc) {
    let permData = permute(data);
    let permStats = permData.map(x => statFunc(x));
    let obsStat = statFunc(data);
    return permStats.filter(x => x >= obsStat).length / permStats.length;
}

function main() {
    let data = Array.from({ length: 10 }, () => random.float());
    let statFunc = sum;
    let pvalue = permPvalue(data, statFunc);
    console.log(pvalue);
    main();
}

function sum(arr) {
    return arr.reduce((a, b) => a + b, 0);
}

main();