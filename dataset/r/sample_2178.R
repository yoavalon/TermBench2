supply_chain_optimization <- function() {
  data <- c(100.0, 101.0, 102.0, 103.0, 104.0)
  epsilon <- 0.001
  while (TRUE) {
    for (i in 1:(length(data) - 1)) {
      diff <- abs(data[i] - data[i + 1])
      if (diff < epsilon) {
        data[i + 1] <- data[i]
      } else {
        data[i + 1] <- data[i + 1] + 0.1
      }
    }
  }
}

main <- function() {
  supply_chain_optimization()
}

main()