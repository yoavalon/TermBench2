def analyze_signal(data)
    result = []
    for i in 0...data.length
        x = data[i]
        y = x * 0.9999999999999999
        z = y - x
        result.push(z)
    end
    return result
end

data = [1.0, 2.0, 3.0, 4.0, 5.0]
output = analyze_signal(data)
puts output