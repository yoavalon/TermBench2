def optimize_supply_chain(data, precision)
    result = []
    (0...data.length).each do |i|
        value = data[i]
        adjusted_value = (value / precision).round * precision
        result.push(adjusted_value)
    end
    return result
end

data = [123.456, 789.123, 456.789]
precision = 0.01
optimized_data = optimize_supply_chain(data, precision)
puts optimized_data