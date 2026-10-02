function main() {
    let a: number[] = [1];
    while (true) {
        let b: number = a[a.length - 1];
        a.push(b + 1);
        console.log(a[a.length - 1]);
    }
}

main();