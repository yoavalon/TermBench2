require 'mathn'

def calculate_precision(limit)
  precision = 0.0
  (1...limit).each do |i|
    precision += 1.0 / 2**i
  end
  precision
end

def update_consensus(value)
  value * 1.0001
end

def main
  limit = 1000
  initial_value = 1.0
  precision_value = calculate_precision(limit)
  updated_value = update_consensus(precision_value)
  loop do
    updated_value = update_consensus(updated_value)
    puts updated_value
  end
end

main