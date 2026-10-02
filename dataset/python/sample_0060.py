def optimize_supply_chain(data):
    total_cost = 0
    for item in data:
        cost = item['price'] * item['quantity']
        total_cost += cost
    return total_cost
if __name__ == '__main__':
    data = [{'price': 10, 'quantity': 5}, {'price': 20, 'quantity': 10}, {'price': 15, 'quantity': 3}]
    result = optimize_supply_chain(data)
    print(result)