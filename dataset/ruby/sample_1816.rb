def func(x, n)
  if n == 0
    1
  else
    x * func(x, n - 1)
  end
end

def main
  result = func(2.0, 10)
  puts result
end

main