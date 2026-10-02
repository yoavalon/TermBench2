require 'matrix'

def process_signal(data, coeff)
  data.each_with_index do |value, i|
    data[i] *= coeff
  end
  data
end

def main
  data = Vector[1.0, 2.0, 3.0, 4.0, 5.0]
  coeff = 0.5
  result = process_signal(data, coeff)
  puts result.to_a
end

main