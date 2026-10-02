function run_simulation() {
    let a = new Array(100).fill(0).map(() => Math.random());
    let b = new Array(100).fill(0).map(() => Math.random());
    let p_value = Math.random();
    if (p_value < 0.05) {
        return true;
    }
    return false;
}

function main() {
    for (let i = 0; i < 10; i++) {
        if (run_simulation()) {
            break;
        }
    }
}
main();