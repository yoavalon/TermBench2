def boundary_conditions(data, threshold)
    result = []
    for i in 0...data.length
        if data[i].abs > threshold
            result.push(i)
        end
        if result.length == 3
            break
        end
    end
    return result
end

if __FILE__ == $0
    data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9]
    threshold = 0.5
    puts boundary_conditions(data, threshold).inspect
end