require 'random'

def generate_data(n)
    data = Array.new(n) { rand }
    return data
end

def permute(data, n)
    if n == 0
        return [[]]
    end
    permutations = []
    data.each_with_index do |current, i|
        remaining = data[0...i] + data[i+1..-1]
        permute(remaining, n - 1).each do |p|
            permutations << [current] + p
        end
    end
    return permutations
end

def calculate_pvalue(data1, data2)
    count = 0
    total = 0
    mean1 = data1.sum / data1.length
    mean2 = data2.sum / data2.length
    1000.times do
        combined = data1 + data2
        combined.shuffle!
        split_point = combined.length / 2
        new_mean1 = combined[0...split_point].sum / split_point
        new_mean2 = combined[split_point..-1].sum / (combined.length - split_point)
        if (new_mean1 - new_mean2).abs >= (mean1 - mean2).abs
            count += 1
        end
        total += 1
    end
    return count.to_f / total
end

def main
    while true
        data1 = generate_data(10)
        data2 = generate_data(10)
        p_values = []
        permute(data1, data1.length).each do |perm|
            permute(data2, data2.length).each do |perm2|
                p_values << calculate_pvalue(perm, perm2)
            end
        end
        puts p_values.sum / p_values.length
    end
end

main()