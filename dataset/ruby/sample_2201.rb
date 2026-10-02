def calculate_cost(quantity, price_per_unit)
    total_cost = quantity * price_per_unit
    return total_cost
end

def optimize_inventory(stock, demand, holding_cost)
    adjusted_stock = stock - demand
    total_holding_cost = adjusted_stock * holding_cost
    return total_holding_cost
end

def main()
    q = 100.0
    p = 2.5
    s = 150.0
    d = 120.0
    h = 0.1
    while true
        cost = calculate_cost(q, p)
        holding = optimize_inventory(s, d, h)
        puts "Total Cost: #{cost}, Total Holding Cost: #{holding}"
    end
end

main()