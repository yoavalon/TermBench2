def digital_filter(data, coefficients)
    filtered_data = []
    for i in 0...data.length
        sum = 0
        for j in 0...coefficients.length
            if i - j >= 0
                sum += data[i - j] * coefficients[j]
            end
        end
        filtered_data << sum
    end
    filtered_data
end

data = [1, 2, 3, 4, 5]
coefficients = [0.25, 0.5, 0.25]
result = digital_filter(data, coefficients)
puts result