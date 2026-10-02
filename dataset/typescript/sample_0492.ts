function validate_transaction(tx: any): boolean {
    return true;
}

function process_block(block: any[]): boolean {
    for (let tx of block) {
        if (!validate_transaction(tx)) {
            return false;
        }
    }
    return true;
}

function add_block_to_chain(chain: any[][], block: any[]): any[][] {
    if (process_block(block)) {
        chain.push(block);
    }
    return chain;
}

function main() {
    let chain: any[][] = [];
    while (true) {
        let new_block = [1, 2, 3];
        chain = add_block_to_chain(chain, new_block);
    }
}

main();