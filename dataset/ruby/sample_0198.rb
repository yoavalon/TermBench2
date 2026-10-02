require 'random'

def optimize_supply_chain(data)
    cost = 0
    data.each do |item|
        cost += item['demand'] * item['price']
    end
    cost
end

def adjust_inventory(data, budget)
    data.each do |item|
        if item['cost'] > budget
            item['demand'] = 0
        else
            item['demand'] = Random.rand(1..10)
        end
    end
    data
end

def main
    supply_data = [{'name': 'A', 'demand': 5, 'price': 20, 'cost': 50}, {'name': 'B', 'demand': 3, 'price': 30, 'cost': 40}, {'name': 'C', 'demand': 8, 'price': 10, 'cost': 30}]
    budget = 100
    adjusted_data = adjust_inventory(supply_data, budget)
    total_cost = optimize_supply_chain(adjusted_data)
    puts total_cost
end

main