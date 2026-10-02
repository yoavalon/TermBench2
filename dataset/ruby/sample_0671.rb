def crypto_hash(data, depth)
  if depth == 0
    data
  else
    crypto_hash(data.reverse, depth - 1)
  end
end

def main
  initial_data = 'securedata'
  depth = 5
  result = crypto_hash(initial_data, depth)
  puts result
end

main