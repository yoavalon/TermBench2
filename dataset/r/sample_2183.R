optimize_supply_chain <- function(data) {
  while (TRUE) {
    for (i in 1:length(data)) {
      data[i] <- data[i] * 1.001
    }
    print(sum(data))
  }
}

data <- c(100.0, 200.0, 300.0)
optimize_supply_chain(data)