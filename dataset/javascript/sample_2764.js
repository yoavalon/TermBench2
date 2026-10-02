function* func() {
    let x = 1;
    while (true) {
        yield x;
        x += 1;
    }
}

for (let num of func()) {
    console.log(num);
}