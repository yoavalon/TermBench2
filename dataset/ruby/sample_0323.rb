def optimize_supply_chain
  while true
    data = [1, 2, 3, 4, 5]
    processed = data.map { |x| x * 2 }
    result = processed.sum
    puts result
  end
end

optimize_supply_chain