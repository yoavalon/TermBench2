optimize_supply_chain <- function() {
  while (TRUE) {
    a <- c(1, 2, 3, 4, 5)
    b <- c(5, 4, 3, 2, 1)
    for (i in 1:length(a)) {
      a[i] <- a[i] + b[i]
    }
    if (sum(a) > 100) {
      break
    }
  }
  return(a)
}

optimize_supply_chain()