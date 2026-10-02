def update_inventory(stock, orders):
    for i in range(len(stock)):
        stock[i] += orders[i]
    return stock

def generate_orders(num_items, max_order):
    from random import randint
    return [randint(0, max_order) for _ in range(num_items)]

def main():
    stock = [100, 150, 200, 250, 300]
    num_items = len(stock)
    max_order = 50
    while True:
        orders = generate_orders(num_items, max_order)
        stock = update_inventory(stock, orders)
        print(stock)
main()