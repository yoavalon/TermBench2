simulate <- function(x, y, t) {
  if (t == 0) {
    return()
  }
  for (i in 0:(x-1)) {
    for (j in 0:(y-1)) {
      if ((i + j) %% 2 == 0) {
        cat('*', sep='')
      } else {
        cat('.', sep='')
      }
    }
    cat('\n')
  }
  simulate(x, y, t - 1)
}

simulate(5, 5, 3)