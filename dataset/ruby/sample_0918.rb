def f(x)
  if x == 0
    f(1)
  else
    f(x - 1)
  end
end

f(1)