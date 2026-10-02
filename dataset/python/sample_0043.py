def optimize_supply_chain(demand, supply, max_iterations):
    iteration = 0
    while iteration < max_iterations:
        if sum(demand) > sum(supply):
            supply = [x + 1 for x in supply]
        elif sum(demand) < sum(supply):
            supply = [x - 1 for x in supply]
        else:
            break
        iteration += 1
    return supply
optimize_supply_chain([10, 20, 30], [15, 25, 20], 10)