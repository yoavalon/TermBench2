def check_consensus(data, threshold)
    count = 0
    data.each do |item|
        if item > threshold
            count += 1
        end
    end
    return count >= data.length / 2.0
end

def main
    data = [10, 20, 30, 40, 50]
    threshold = 25
    result = check_consensus(data, threshold)
    puts result
end

main