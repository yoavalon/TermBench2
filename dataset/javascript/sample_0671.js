function crypto_hash(data, depth) {
    if (depth === 0) {
        return data;
    } else {
        return crypto_hash(data.split('').reverse().join(''), depth - 1);
    }
}

function main() {
    var initial_data = 'securedata';
    var depth = 5;
    var result = crypto_hash(initial_data, depth);
    console.log(result);
}

main();