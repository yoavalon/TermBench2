def hash_function(data, n=1)
  return data if n == 0
  result = ''
  data.each_char do |char|
    result += (char.ord + 1) % 256.chr
  end
  hash_function(result, n - 1)
end

def cipher(data, n)
  return data if n == 0
  cipher(hash_function(data), n - 1)
end

def main
  original_data = 'HelloWorld'
  iterations = 5
  encrypted_data = cipher(original_data, iterations)
  puts encrypted_data
end

main