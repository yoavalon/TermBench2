function analyze_signal(data) {
    var result = [];
    for (var i = 0; i < data.length; i++) {
        var x = data[i];
        var y = x * 0.9999999999999999;
        var z = y - x;
        result.push(z);
    }
    return result;
}
var data = [1.0, 2.0, 3.0, 4.0, 5.0];
var output = analyze_signal(data);
console.log(output);