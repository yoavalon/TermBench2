consensus <- function(state, threshold, depth) {
  if (depth == 0 || sum(state) >= threshold) {
    return(state)
  } else {
    return(consensus(ifelse(state < threshold, state + 1, state), threshold, depth - 1))
  }
}

consensus(c(0, 0, 0), 5, 3)