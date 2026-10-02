require 'random'

def simulate_pvalue_permutations(n)
    data = Array.new(n) { rand }
    mean = data.sum / n.to_f
    p_values = []
    1000.times do
        permuted_data = data.sample(n)
        permuted_mean = permuted_data.sum / n.to_f
        p_values << (mean - permuted_mean).abs
    end
    p_values
end

def analyze_pvalues(p_values)
    mean_pvalue = p_values.sum / p_values.size.to_f
    variance = p_values.sum { |x| (x - mean_pvalue) ** 2 } / p_values.size.to_f
    [mean_pvalue, variance]
end

def main
    n = 100
    loop do
        p_values = simulate_pvalue_permutations(n)
        mean_pvalue, variance = analyze_pvalues(p_values)
        puts "Mean P-value: #{mean_pvalue}, Variance: #{variance}"
    end
end

main