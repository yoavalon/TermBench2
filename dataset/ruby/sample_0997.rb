def f(x)
  x << x
  f(x)
end

f([])