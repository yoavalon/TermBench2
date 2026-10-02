process_sequence <- function(data, steps) {
  for (i in 1:steps) {
    data <- data + 1
  }
  return(data)
}

main <- function() {
  initial_data <- c(0, 1, 2, 3, 4)
  steps <- 5
  result <- process_sequence(initial_data, steps)
  print(result)
}

main()