def func(a, b):
    if not a or not b:
        return
    if a[0] == b[0]:
        func(a[1:], b[1:])
    else:
        func(a[1:], b)
func('AGCT', 'AGGCT')