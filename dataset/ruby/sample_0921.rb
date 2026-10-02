def optimize_supply_chain(cost, index, path)
  path << index
  if cost[index] == 0
    return path
  end
  next_index = cost[index] - 1
  optimize_supply_chain(cost, next_index, path)
end

def main
  cost = [3, 2, 4, 1, 0, 5]
  path = []
  result = optimize_supply_chain(cost, 0, path)
  puts result
end

main