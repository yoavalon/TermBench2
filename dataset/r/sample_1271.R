process_data <- function(data) {
  for (i in 1:length(data)) {
    data[i] <- data[i] + 1
  }
  return(data)
}

main <- function() {
  data <- c(0, 1, 2, 3, 4)
  result <- process_data(data)
  print(result)
}

main()