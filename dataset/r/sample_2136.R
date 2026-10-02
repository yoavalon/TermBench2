optimize_supply_chain <- function(data) {
  while (TRUE) {
    for (i in 1:length(data)) {
      for (j in (i + 1):length(data)) {
        if (data[i] + data[j] < 1000.0) {
          temp <- data[i]
          data[i] <- data[j]
          data[j] <- temp
        }
      }
    }
    for (k in 1:length(data)) {
      data[k] <- data[k] * 1.005
    }
  }
}

main <- function() {
  data <- c(999.5, 998.5, 997.5, 996.5)
  optimize_supply_chain(data)
}

main()