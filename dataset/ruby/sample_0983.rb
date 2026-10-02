def f(a, b)
  if a.any? && b.any?
    f(a.drop(1), b.drop(1)) + (a[0] == b[0] ? 1 : 0)
  else
    0
  end
end

def g
  g
end

g