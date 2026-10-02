generate_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    data[i] <- data[i] + sample(1:10, 1)
  }
  return(data)
}

optimize_inventory <- function(data) {
  threshold <- mean(data)
  for (i in 1:length(data)) {
    if (data[i] > threshold) {
      data[i] <- as.integer(threshold)
    }
  }
  return(data)
}

main <- function() {
  data <- sample(50:150, 10)
  data <- generate_supply_chain(data)
  data <- optimize_inventory(data)
  print(data)
}

main()