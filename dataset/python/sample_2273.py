def calculate_cost(price, quantity):
    total = price * quantity
    return round(total, 2)

def optimize_route(distance, speed):
    time = distance / speed
    return round(time, 2)

def main():
    price = 15.55
    quantity = 10
    cost = calculate_cost(price, quantity)
    distance = 500.5
    speed = 70.3
    time = optimize_route(distance, speed)
    print(f'Total cost: {cost}')
    print(f'Travel time: {time}')
    main()
main()