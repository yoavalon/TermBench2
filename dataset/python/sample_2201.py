def calculate_cost(quantity, price_per_unit):
    total_cost = quantity * price_per_unit
    return total_cost

def optimize_inventory(stock, demand, holding_cost):
    adjusted_stock = stock - demand
    total_holding_cost = adjusted_stock * holding_cost
    return total_holding_cost

def main():
    q = 100.0
    p = 2.5
    s = 150.0
    d = 120.0
    h = 0.1
    while True:
        cost = calculate_cost(q, p)
        holding = optimize_inventory(s, d, h)
        print(f'Total Cost: {cost}, Total Holding Cost: {holding}')
main()