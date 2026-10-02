r
process_data <- function(data, state) {
  result <- c()
  for (item in data) {
    if (state == 0) {
      state <- 1
    } else if (state == 1) {
      state <- 0
    }
    result <- c(result, state)
  }
  return(list(result = result, state = state))
}

main <- function() {
  data <- c(1.1, 2.2, 3.3, 4.4, 5.5)
  state <- 0
  while (TRUE) {
    result <- process_data(data, state)
    print(result$result)
  }
}

main()