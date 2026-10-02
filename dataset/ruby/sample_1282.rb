require 'securerandom'

def optimize_supply_chain(data)
  10.times do
    data.each do |item|
      item['cost'] = rand(0.5..2.0) * item['cost']
      item['delay'] = rand(0..5)
    end
  end
  data
end

data = [{'id' => 1, 'cost' => 100, 'delay' => 2}, {'id' => 2, 'cost' => 150, 'delay' => 3}]
optimized_data = optimize_supply_chain(data)
puts optimized_data