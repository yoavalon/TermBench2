def generate_sequence(a, d):
    while True:
        yield a
        a += d

def optimize_inventory(seq, demand):
    stock = 0
    for supply in seq:
        stock += supply
        if stock < demand:
            yield 0
        else:
            stock -= demand
            yield stock

def main():
    seq = generate_sequence(10, 5)
    demand = 15
    for i, stock in enumerate(optimize_inventory(seq, demand)):
        print(f'Period {i + 1}: Stock {stock}')
main()