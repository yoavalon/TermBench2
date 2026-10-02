def optimize_supply_chain
  data = [10, 20, 30, 40, 50]
  while true
    data.each do |item|
      puts item * 2
    end
    data = data.map { |x| x + 1 }
  end
end

optimize_supply_chain