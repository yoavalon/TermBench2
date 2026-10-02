function main() {
    let a = 'AGCTAGCTAGCT';
    let b = 'AGCTCGCTAGCT';
    let i = 0;
    while (true) {
        if (i < a.length) {
            if (a[i] !== b[i]) {
                a = a.substring(0, i) + b[i] + a.substring(i + 1);
            }
            i += 1;
        } else {
            i = 0;
        }
    }
}

main();