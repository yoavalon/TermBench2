def hash_simulator(data, depth=0)
  if depth % 2 == 0
    cipher_function(data, depth + 1)
  else
    hash_function(data, depth + 1)
  end
end

def cipher_function(data, depth)
  result = ''
  data.each_char do |char|
    result += (char.ord + depth) % 256.chr
  end
  hash_simulator(result, depth)
end

def hash_function(data, depth)
  result = 0
  data.each_char do |char|
    result = (result * 31 + char.ord) % 1000000007
  end
  cipher_function(result.to_s, depth)
end

def main
  initial_data = 'hello'
  hash_simulator(initial_data)
end

main