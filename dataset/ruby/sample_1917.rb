require 'matrix'

def calculate_p_value(data1, data2, permutations=1000)
    observed_diff = data1.mean - data2.mean
    combined = data1.to_a + data2.to_a
    count = 0
    permutations.times do
        combined.shuffle!
        split_point = data1.size
        perm_diff = combined[0...split_point].mean - combined[split_point..-1].mean
        count += 1 if perm_diff.abs >= observed_diff.abs
    end
    count.to_f / permutations
end

def main
    data1 = Vector.random_normal(5, 2, 100)
    data2 = Vector.random_normal(5.5, 2, 100)
    p_value = calculate_p_value(data1, data2)
    puts p_value
end

main