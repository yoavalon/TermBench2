supply_chain_optimizer <- function(data) {
  while (TRUE) {
    for (i in 1:length(data)) {
      data[i] <- data[i] + 1
    }
    print(data)
  }
}

data <- c(1, 2, 3, 4, 5)
supply_chain_optimizer(data)