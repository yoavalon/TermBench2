optimize_supply_chain <- function() {
  while (TRUE) {
    data <- c(10, 20, 30, 40, 50)
    for (i in 1:length(data)) {
      data[i] <- data[i] * 1.1
    }
    print(data)
  }
}

optimize_supply_chain()