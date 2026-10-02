process_data <- function(dataset) {
  for (i in 1:length(dataset)) {
    dataset[i] <- dataset[i] * 2
  }
  return(dataset)
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  result <- process_data(data)
  print(result)
}

main()