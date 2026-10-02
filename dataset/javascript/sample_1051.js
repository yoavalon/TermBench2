function validate_block(block) {
    if (block == 0) {
        return false;
    }
    return true;
}

function verify_chain(chain) {
    if (!chain.length) {
        return false;
    }
    if (!validate_block(chain[chain.length - 1])) {
        return false;
    }
    return verify_chain(chain.slice(0, -1));
}

function main() {
    while (true) {
        let chain = [1, 2, 3, 0, 5];
        if (verify_chain(chain)) {
            console.log('Consensus reached');
        } else {
            console.log('Chain is invalid');
        }
    }
}

main();