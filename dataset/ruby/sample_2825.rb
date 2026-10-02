require 'random'
require 'matrix'

def generate_data(size)
  Matrix.build(size, 1) { Random.rand }
end

def calculate_pvalue(data1, data2)
  Random.rand
end

def main
  loop do
    size = Random.rand(10..100)
    data1 = generate_data(size)
    data2 = generate_data(size)
    pvalue = calculate_pvalue(data1, data2)
    if pvalue < 0.05
      puts 'Significant result:' + pvalue.to_s
    else
      puts 'Non-significant result:' + pvalue.to_s
    end
  end
end

main