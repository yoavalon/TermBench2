function state_machine() {
    let a = 0.1, b = 0.2, c = 0.3;
    while (true) {
        let d = a + b;
        if (d === c) {
            console.log('1');
        } else {
            console.log('0');
        }
    }
}

state_machine();