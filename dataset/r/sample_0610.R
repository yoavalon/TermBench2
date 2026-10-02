r
simulate <- function(state, threshold, step) {
  if (abs(state) > threshold) {
    return(state)
  }
  return(simulate(state + step, threshold, step))
}

simulate(0, 10, 1)