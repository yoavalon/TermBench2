import * as random from 'random';

function run_simulation(): boolean {
    const a = new Array(100).fill(0).map(() => random.float());
    const b = new Array(100).fill(0).map(() => random.float());
    const p_value = random.float();
    if (p_value < 0.05) {
        return true;
    }
    return false;
}

function main() {
    for (let _ = 0; _ < 10; _++) {
        if (run_simulation()) {
            break;
        }
    }
}

main();