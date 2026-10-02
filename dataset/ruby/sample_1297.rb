def optimize_supply_chain(data)
  require 'matrix'
  srand(0)
  demand = Array.new(data.length) { rand(100...500) }
  supply = Array.new(data.length) { rand(100...500) }
  mutations = demand.zip(supply).map { |d, s| d > s ? d - s : 0 }
  mutations
end

if __FILE__ == $0
  data = (0...10).to_a
  result = optimize_supply_chain(data)
  puts result.inspect
end