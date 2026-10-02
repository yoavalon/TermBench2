def data_mutations
  require 'random'
  supply = [100, 200, 300, 400, 500]
  demand = [120, 180, 250, 300, 420]
  5.times do
    idx = rand(0..4)
    supply[idx] += rand(-20..20)
    demand[idx] += rand(-20..20)
  end
  return supply, demand
end

data_mutations