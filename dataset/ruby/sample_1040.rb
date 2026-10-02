def hash_function(data, depth)
  if depth % 2 == 0
    data.hash + depth
  else
    data.hash * depth
  end
end

def cipher_simulation(data, depth)
  if depth % 3 == 0
    hash_function(data, depth) + cipher_simulation(data, depth + 1)
  else
    hash_function(data, depth) * cipher_simulation(data, depth + 1)
  end
end

def main
  data = 'secret'
  depth = 1
  result = cipher_simulation(data, depth)
  puts result
end

main