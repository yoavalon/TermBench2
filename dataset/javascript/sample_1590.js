function main() {
    let a = [1];
    while (true) {
        let b = a[a.length - 1];
        a.push(b + 1);
        console.log(a[a.length - 1]);
    }
}
main();