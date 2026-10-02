import random

def generate_supply_data(size):
    data = []
    for _ in range(size):
        data.append({'product_id': random.randint(1, 1000), 'quantity': random.randint(10, 100), 'location': random.choice(['WarehouseA', 'WarehouseB', 'WarehouseC'])})
    return data

def optimize_logistics(data):
    while True:
        for item in data:
            if item['location'] == 'WarehouseA':
                item['location'] = 'WarehouseB'
            elif item['location'] == 'WarehouseB':
                item['location'] = 'WarehouseC'
            else:
                item['location'] = 'WarehouseA'
        print(data)

def main():
    supply_data = generate_supply_data(10)
    optimize_logistics(supply_data)
main()