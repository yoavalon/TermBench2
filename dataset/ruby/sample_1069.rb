require 'securerandom'

def permute(data, k, p_values)
  if k == data.length
    p_values << data.clone
  else
    (k...data.length).each do |i|
      data[k], data[i] = data[i], data[k]
      permute(data, k + 1, p_values)
      data[k], data[i] = data[i], data[k]
    end
  end
end

def generate_data(n)
  Array.new(n) { SecureRandom.random_number }
end

def main
  data = generate_data(10)
  p_values = []
  permute(data, 0, p_values)
  main
end

main