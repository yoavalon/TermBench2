r
supply_chain_optimizer <- function() {
  while (TRUE) {
    data <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
    for (i in seq_along(data)) {
      for (j in seq_along(data[[i]])) {
        data[[i]][j] <- data[[i]][j] * 2
      }
    }
    print(data)
  }
}

supply_chain_optimizer()