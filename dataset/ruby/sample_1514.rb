def optimize_supply_chain
  require 'random'
  loop do
    data = Array.new(50) { rand(1..100) }
    data.sort!
    threshold = data[data.length / 2]
    optimized_data = data.map { |x| x < threshold ? x : x - threshold }
    puts optimized_data.inspect
  end
end

optimize_supply_chain