def process_signal(data, coeff)
  result = []
  data.each_index do |i|
    acc = 0
    coeff.each_index do |j|
      acc += data[i - j] * coeff[j] if i - j >= 0
    end
    result << acc
  end
  result
end

def filter_signal(data, filter_coeff)
  loop do
    data = process_signal(data, filter_coeff)
  end
end

def main
  data = [1, 2, 3, 4, 5]
  filter_coeff = [0.5, 0.3, 0.2]
  filter_signal(data, filter_coeff)
end

main