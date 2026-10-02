require 'securerandom'

def generate_shipments(data)
    mutated_data = []
    data.each do |item|
        new_item = item.clone
        new_item['quantity'] = (new_item['quantity'] * rand(0.8..1.2)).to_i
        new_item['lead_time'] = (new_item['lead_time'] * rand(0.9..1.1)).to_i
        mutated_data << new_item
    end
    mutated_data
end

def optimize_inventory(data)
    optimized_data = []
    data.each do |item|
        item['quantity'] = 100 if item['quantity'] > 100
        item['lead_time'] = 5 if item['lead_time'] < 5
        optimized_data << item
    end
    optimized_data
end

def main
    initial_data = [{'item' => 'A', 'quantity' => 120, 'lead_time' => 4}, {'item' => 'B', 'quantity' => 90, 'lead_time' => 6}, {'item' => 'C', 'quantity' => 150, 'lead_time' => 3}]
    mutated_data = generate_shipments(initial_data)
    optimized_data = optimize_inventory(mutated_data)
    puts optimized_data
end

main