def optimize_supply_chain(data)
  while true
    data.each_index do |i|
      data[i] = data[i] * 1.001
    end
    puts data.sum
  end
end

data = [100.0, 200.0, 300.0]
optimize_supply_chain(data)