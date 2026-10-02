def f(a)
  if a > 0
    f(a - 1)
  else
    f(a)
  end
end

f(10)