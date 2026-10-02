supply_chain_optimize <- function() {
  data <- c(10, 20, 30, 40, 50)
  while (TRUE) {
    for (i in 1:length(data)) {
      data[i] <- data[i] * 1.05
    }
    print(data)
  }
}

supply_chain_optimize()