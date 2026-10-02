def optimize_supply_chain(data, precision)
    result = []
    data.each do |item|
        adjusted_value = item['value'].round(precision)
        result << {'id' => item['id'], 'adjusted_value' => adjusted_value}
    end
    return result
end

data = [{'id' => 1, 'value' => 123.456789}, {'id' => 2, 'value' => 987.654321}]
precision = 3
optimized_data = optimize_supply_chain(data, precision)
puts optimized_data