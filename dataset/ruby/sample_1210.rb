ruby
def optimize_supply_chain(data)
  return [] if data.empty?
  cost = Float::INFINITY
  route = []
  for i in 0...data.length
    for j in (i + 1)...data.length
      temp_cost = data[i][0] + data[j][1]
      if temp_cost < cost
        cost = temp_cost
        route = [data[i], data[j]]
      end
    end
  end
  route
end

data = [[10, 20], [15, 25], [5, 30], [20, 10]]
result = optimize_supply_chain(data)
puts result.inspect