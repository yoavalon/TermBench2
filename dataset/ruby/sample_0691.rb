def consensus(state, threshold, depth)
  if depth == 0 || state.sum >= threshold
    state
  else
    consensus(state.map { |x| x < threshold ? x + 1 : x }, threshold, depth - 1)
  end
end

consensus([0, 0, 0], 5, 3)