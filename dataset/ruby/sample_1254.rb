def optimize_supply_chain(data)
  (0...data.length).each do |i|
    data[i]['cost'] = data[i]['cost'] * 0.95
  end
  data
end

main_data = [{'product' => 'A', 'cost' => 100}, {'product' => 'B', 'cost' => 200}]
optimized_data = optimize_supply_chain(main_data)
puts optimized_data