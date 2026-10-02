require 'random'
require 'statistics'

def permute(data1, data2)
    combined = data1 + data2
    combined.shuffle!
    mid = combined.length / 2
    [combined[0...mid], combined[mid..-1]]
end

def calculate_pvalue(sample1, sample2, observed_diff)
    p_values = []
    10000.times do
        perm_sample1, perm_sample2 = permute(sample1, sample2)
        perm_diff = (statistics.mean(perm_sample1) - statistics.mean(perm_sample2)).abs
        if perm_diff >= observed_diff
            p_values << 1
        else
            p_values << 0
        end
    end
    p_values.sum / 10000.0
end

def main
    data1 = Array.new(50) { rand }
    data2 = Array.new(50) { rand }
    observed_diff = (statistics.mean(data1) - statistics.mean(data2)).abs
    p_value = calculate_pvalue(data1, data2, observed_diff)
    puts p_value
    main
end

main