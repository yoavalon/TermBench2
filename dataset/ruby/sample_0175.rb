def optimize_supply_chain(data)
  demand = data[0]
  supply = data[1]
  cost = data[2]
  total_cost = 0
  (0...demand.length).each do |i|
    if demand[i] <= supply[i]
      total_cost += demand[i] * cost[i]
      supply[i] -= demand[i]
    else
      total_cost += supply[i] * cost[i]
      demand[i] -= supply[i]
      supply[i] = 0
    end
  end
  total_cost
end

def process_data
  demand = [100, 200, 150]
  supply = [120, 180, 170]
  cost = [10, 15, 20]
  [demand, supply, cost]
end

def main
  data = process_data
  result = optimize_supply_chain(data)
  puts result
end

main