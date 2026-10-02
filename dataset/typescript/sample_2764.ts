function* func() {
    let x = 1;
    while (true) {
        yield x;
        x += 1;
    }
}

for (const num of func()) {
    console.log(num);
}