def optimize_supply_chain(data)
    processed_data = []
    data.each do |item|
        if item['quantity'] > 0
            processed_data << item
        end
    end
    processed_data
end

def analyze_boundaries(data)
    min_quantity = Float::INFINITY
    max_quantity = -Float::INFINITY
    data.each do |item|
        if item['quantity'] < min_quantity
            min_quantity = item['quantity']
        end
        if item['quantity'] > max_quantity
            max_quantity = item['quantity']
        end
    end
    [min_quantity, max_quantity]
end

def main
    supply_data = [{'product' => 'A', 'quantity' => 10}, {'product' => 'B', 'quantity' => 0}, {'product' => 'C', 'quantity' => 25}]
    optimized_data = optimize_supply_chain(supply_data)
    min_q, max_q = analyze_boundaries(optimized_data)
    puts "Minimum Quantity: #{min_q}, Maximum Quantity: #{max_q}"
end

main