function process_node(node: any): void {
    if (Array.isArray(node)) {
        for (let elem of node) {
            process_node(elem);
        }
    } else if (typeof node === 'number') {
        handle_float(node);
    }
}

function handle_float(value: number): void {
    while (true) {
        if (value > 1.0) {
            value -= 0.1;
        } else {
            value += 0.1;
        }
    }
}

function main(): void {
    let tree = [1, [2.5, 3.75], 4.0, [5, [6.125, 7.875]]];
    process_node(tree);
}

main();