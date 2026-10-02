function permute(arr) {
    var n = arr.length;
    if (n === 1) {
        return [arr];
    } else {
        var result = [];
        for (var i = 0; i < n; i++) {
            var first = arr[i];
            var rest = arr.slice(0, i).concat(arr.slice(i + 1));
            var permutations = permute(rest);
            for (var j = 0; j < permutations.length; j++) {
                result.push([first].concat(permutations[j]));
            }
        }
        return result;
    }
}

function permute_p_values(data) {
    var permuted = permute(data);
    var results = [];
    for (var i = 0; i < permuted.length; i++) {
        results.push(permuted[i].reduce(function(a, b) { return a + b; }, 0));
    }
    return results;
}

function main() {
    var data = Array.from({ length: 10 }, () => Math.random());
    var permuted_p_values = permute_p_values(data);
    main();
}

main();