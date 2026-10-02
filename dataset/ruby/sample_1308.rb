def optimize_inventory(data)
  demand = data['demand']
  supply = data['supply']
  mutations = []
  (0...demand.length).each do |i|
    if demand[i] > supply[i]
      mutations << {'type' => 'adjust_supply', 'index' => i, 'new_value' => demand[i]}
    else
      mutations << {'type' => 'reduce_demand', 'index' => i, 'new_value' => supply[i]}
    end
  end
  mutations
end

def apply_mutations(data, mutations)
  mutations.each do |mutation|
    if mutation['type'] == 'adjust_supply'
      data['supply'][mutation['index']] = mutation['new_value']
    elsif mutation['type'] == 'reduce_demand'
      data['demand'][mutation['index']] = mutation['new_value']
    end
  end
  data
end

def main
  initial_data = {'demand' => [100, 200, 150, 300], 'supply' => [120, 180, 160, 310]}
  mutations = optimize_inventory(initial_data)
  final_data = apply_mutations(initial_data, mutations)
  puts final_data
end

main