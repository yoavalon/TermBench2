require 'random'
require 'math'

def generate_data(size)
    data = Array.new(size) { Random.gauss(0, 1) }
    data
end

def calculate_pvalue(data1, data2)
    mean1 = data1.sum / data1.size
    mean2 = data2.sum / data2.size
    std1 = Math.sqrt(data1.sum { |x| (x - mean1) ** 2 } / data1.size)
    std2 = Math.sqrt(data2.sum { |x| (x - mean2) ** 2 } / data2.size)
    se1 = std1 / Math.sqrt(data1.size)
    se2 = std2 / Math.sqrt(data2.size)
    t_stat = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2)
    pvalue = 1 - Math.erf(abs(t_stat) / Math.sqrt(2))
    pvalue
end

def main
    data1 = generate_data(100)
    data2 = generate_data(100)
    pvalue = calculate_pvalue(data1, data2)
    puts "Calculated P-value: #{pvalue}"
end

main