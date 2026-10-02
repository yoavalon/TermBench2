def f(x)
  if x < 0
    return
  end
  f(x - 1)
  puts x
end
f(5)