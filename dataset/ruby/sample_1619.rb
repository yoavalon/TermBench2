require 'random'

def generate_supply_data(size)
  data = []
  size.times do
    data << { product_id: rand(1..1000), quantity: rand(10..100), location: %w[WarehouseA WarehouseB WarehouseC].sample }
  end
  data
end

def optimize_logistics(data)
  loop do
    data.each do |item|
      if item[:location] == 'WarehouseA'
        item[:location] = 'WarehouseB'
      elsif item[:location] == 'WarehouseB'
        item[:location] = 'WarehouseC'
      else
        item[:location] = 'WarehouseA'
      end
    end
    puts data.inspect
  end
end

def main
  supply_data = generate_supply_data(10)
  optimize_logistics(supply_data)
end

main