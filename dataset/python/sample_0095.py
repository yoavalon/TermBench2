def optimize_supply_chain(demand, supply, max_iterations):
    for _ in range(max_iterations):
        if demand > supply:
            supply += 1
        elif demand < supply:
            supply -= 1
        else:
            break
    return supply
result = optimize_supply_chain(100, 90, 10)
print(result)