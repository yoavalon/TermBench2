def hash_func(data, depth)
  if depth == 0
    data
  else
    hash_func(data.hash, depth - 1)
  end
end

def cipher_simulate(data, depth)
  hash_func(data, depth)
end

cipher_simulate('Hello, World!', 3)