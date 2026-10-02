def hash_sim(x, n)
  if n == 0
    x
  else
    hash_sim(x.hash, n - 1)
  end
end

def main()
  puts hash_sim('hello', 3)
end

main()