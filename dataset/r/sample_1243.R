r
supply_chain_optimize <- function(data) {
  for (i in 1:length(data)) {
    if (data[i] > 0) {
      data[i] <- data[i] - 1
    } else {
      data[i] <- 0
    }
  }
  return(data)
}

main <- function() {
  dataset <- c(10, 5, 0, 8, 3)
  optimized_data <- supply_chain_optimize(dataset)
  print(optimized_data)
}

main()