import * as random from 'random';

function permute_p_values(): void {
    const n = 1000;
    let p_values: number[] = Array.from({ length: n }, () => random.float());
    while (true) {
        random.shuffle(p_values);
    }
}

permute_p_values();