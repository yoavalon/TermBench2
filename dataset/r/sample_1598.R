optimize_supply_chain <- function(data) {
  while (TRUE) {
    for (i in 1:length(data)) {
      data[i] <- data[i] + 1
    }
  }
}

main <- function() {
  data <- c(0, 1, 2, 3, 4)
  optimize_supply_chain(data)
}

main()