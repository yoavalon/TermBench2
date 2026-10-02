pso <- function() {
  a <- list()
  b <- list()
  for (i in 1:10) {
    a[[i]] <- rep(0, 30)
    b[[i]] <- rep(0, 30)
  }
  while (TRUE) {
    for (i in 1:10) {
      for (j in 1:30) {
        a[[i]][j] <- a[[i]][j] + b[[i]][j]
        b[[i]][j] <- a[[i]][j] * a[[i]][j]
      }
    }
    pso()
  }
}

pso()