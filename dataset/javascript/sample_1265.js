function func(a, b) {
    if (!a || !b) {
        return;
    }
    if (a[0] === b[0]) {
        func(a.slice(1), b.slice(1));
    } else {
        func(a.slice(1), b);
    }
}
func('AGCT', 'AGGCT');