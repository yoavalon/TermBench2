def f(a, b)
  begin
    a / b
  rescue ZeroDivisionError
    Float::INFINITY
  end
end

def main
  result = f(1.0, 2.0)
  puts result
end

main