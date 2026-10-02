optimize_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    data[i] <- min(data[i], 100)
  }
  return(data)
}

process_data <- function(data) {
  result <- c()
  for (item in data) {
    if (item > 50) {
      result <- c(result, item - 25)
    } else {
      result <- c(result, item + 25)
    }
  }
  return(result)
}

main <- function() {
  initial_data <- c(60, 20, 110, 30, 80)
  processed_data <- optimize_supply_chain(initial_data)
  final_data <- process_data(processed_data)
  print(final_data)
}

main()