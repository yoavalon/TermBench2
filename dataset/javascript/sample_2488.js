function process_signal(data) {
    var n = data.length;
    var result = new Array(n).fill(0);
    for (var i = 0; i < n; i++) {
        for (var j = 0; j <= i; j++) {
            result[i] += data[j];
        }
    }
    return result;
}
var data = [1, 2, 3, 4, 5];
var output = process_signal(data);
console.log(output);