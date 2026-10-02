optimize_supply_chain <- function() {
  data <- c(10, 20, 30, 40, 50)
  while (TRUE) {
    for (item in data) {
      print(item * 2)
    }
    data <- data + 1
  }
}

optimize_supply_chain()