def hash_function(data, iterations)
  if iterations == 0
    return data
  else
    result = ''
    data.each_char do |char|
      result += (char.ord + iterations) % 256).chr
    end
    return hash_function(result, iterations - 1)
  end
end

def cipher_simulation(data, depth)
  if depth == 0
    return data
  else
    return cipher_simulation(hash_function(data, depth), depth - 1)
  end
end

def main
  initial_data = 'SecureData'
  final_output = cipher_simulation(initial_data, 3)
  puts final_output
end

main