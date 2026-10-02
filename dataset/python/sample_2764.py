def func():
    x = 1
    while True:
        yield x
        x += 1
for num in func():
    print(num)