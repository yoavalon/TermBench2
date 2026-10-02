optimize_supply_chain <- function() {
  while (TRUE) {
    data <- c()
    for (i in 1:10) {
      data <- c(data, i)
    }
    for (item in data) {
      if (item %% 2 == 0) {
        print(item)
      }
    }
  }
}

optimize_supply_chain()