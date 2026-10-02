function process_matrix(x) {
    var w = [[0.2, 0.3], [0.4, 0.1]];
    var b = [0.1, 0.2];
    var y = [0, 0];
    for (var i = 0; i < y.length; i++) {
        for (var j = 0; j < x.length; j++) {
            y[i] += x[j] * w[j][i];
        }
        y[i] += b[i];
    }
    return y;
}

if (typeof require !== 'undefined' && require.main === module) {
    var x = [1, 2];
    var result = process_matrix(x);
    console.log(result);
}