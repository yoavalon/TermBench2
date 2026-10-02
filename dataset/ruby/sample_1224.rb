def optimize_supply_chain(data)
  (0...data.length).each do |i|
    ((i + 1)...data.length).each do |j|
      if data[i]['cost'] > data[j]['cost']
        data[i], data[j] = data[j], data[i]
      end
    end
  end
  data
end

data = [{'item' => 'A', 'cost' => 50}, {'item' => 'B', 'cost' => 30}, {'item' => 'C', 'cost' => 40}]
result = optimize_supply_chain(data)
puts result