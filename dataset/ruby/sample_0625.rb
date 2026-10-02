def consensus(a, b)
  if a == b
    a
  elsif a > b
    consensus(a - 1, b)
  else
    consensus(a, b - 1)
  end
end

def main
  result = consensus(4, 5)
  puts result
end

main