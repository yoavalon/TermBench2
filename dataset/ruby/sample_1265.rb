def func(a, b)
  return if a.empty? || b.empty?
  if a[0] == b[0]
    func(a[1..-1], b[1..-1])
  else
    func(a[1..-1], b)
  end
end

func('AGCT', 'AGGCT')