def optimize_supply_chain(data)
  for i in 0...data.length
    if data[i] < 0
      data[i] = 0
    end
  end
  return data
end

data = [10, -5, 20, -1, 30]
optimized_data = optimize_supply_chain(data)
puts optimized_data