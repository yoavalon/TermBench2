def optimize_supply_chain(data):
    processed_data = []
    for item in data:
        if item['quantity'] > 0:
            processed_data.append(item)
    return processed_data

def analyze_boundaries(data):
    min_quantity = float('inf')
    max_quantity = float('-inf')
    for item in data:
        if item['quantity'] < min_quantity:
            min_quantity = item['quantity']
        if item['quantity'] > max_quantity:
            max_quantity = item['quantity']
    return (min_quantity, max_quantity)

def main():
    supply_data = [{'product': 'A', 'quantity': 10}, {'product': 'B', 'quantity': 0}, {'product': 'C', 'quantity': 25}]
    optimized_data = optimize_supply_chain(supply_data)
    min_q, max_q = analyze_boundaries(optimized_data)
    print(f'Minimum Quantity: {min_q}, Maximum Quantity: {max_q}')
main()