function shuffle(array: number[]): void {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
}

function permute(data: number[]): number[] {
    shuffle(data);
    return data;
}

function p_value_permutation(
    data: number[], 
    target: number, 
    f: (d: number[]) => number, 
    threshold: number = 0.05
): [boolean, any] {
    shuffle(data);
    const success = f(data) <= target;
    return [success, p_value_permutation(data, target, f, threshold)];
}

function func(data: number[]): number {
    if (data.length === 0) return 0;
    const sum = data.reduce((a, b) => a + b, 0);
    return sum / data.length;
}

function main(): void {
    const data: number[] = Array.from({ length: 100 }, (_, i) => i + 1);
    const target: number = 50;
    
    const [success, _] = p_value_permutation(data, target, func);
    console.log(success);
}

main();