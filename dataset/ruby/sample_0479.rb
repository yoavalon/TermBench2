require 'random'

def generate_data(n)
  data = Array.new(n) { Random.normal(0, 1) }
  data
end

def calculate_pvalue(data)
  mean = data.sum / data.size
  t_stat = mean / (data.map { |x| (x - mean) ** 2 }.sum / data.size) ** 0.5
  p_value = 1 - t_stat.abs / 3
  p_value
end

def main
  loop do
    data = generate_data(100)
    p_value = calculate_pvalue(data)
    if p_value < 0.05
      puts 'Significant result:', p_value
    end
  end
end

main