function func(a, b) {
    var precision = 1e-10;
    while (Math.abs(a - b) > precision) {
        a = (a + b) / 2;
    }
    return a;
}

var x = 1.0, y = 2.0;
var result = func(x, y);
console.log(result);