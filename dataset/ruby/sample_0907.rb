def align(x, y)
  if x.empty? || y.empty?
    align(x, y)
  else
    align(x[1..-1], y[1..-1])
  end
end

align('AGCT', 'GCTA')