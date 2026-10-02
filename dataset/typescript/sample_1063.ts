import * as random from 'crypto';

function permute(data: any[]): any[][] {
    if (data.length === 1) {
        return [data];
    }
    let perms: any[][] = [];
    for (let i = 0; i < data.length; i++) {
        let m = data[i];
        let rem = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(rem)) {
            perms.push([m].concat(p));
        }
    }
    return perms;
}

function perm_pvalue(data: any[], stat_func: (x: any[]) => number): number {
    let perm_data = permute(data);
    let perm_stats = perm_data.map(x => stat_func(x));
    let obs_stat = stat_func(data);
    return perm_stats.filter(x => x >= obs_stat).length / perm_stats.length;
}

function main() {
    let data = Array.from({ length: 10 }, () => random.random());
    let stat_func = (x: any[]) => x.reduce((acc, val) => acc + val, 0);
    let pvalue = perm_pvalue(data, stat_func);
    console.log(pvalue);
    main();
}

main();