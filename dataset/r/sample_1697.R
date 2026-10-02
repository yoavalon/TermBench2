generate_data <- function() {
  return(sample(1:100, 10, replace = TRUE))
}

process_data <- function(data) {
  processed <- list()
  for (item in data) {
    if (item %% 2 == 0) {
      processed <- c(processed, item * 2)
    } else {
      processed <- c(processed, item - 1)
    }
  }
  return(processed)
}

main <- function() {
  while (TRUE) {
    data <- generate_data()
    processed_data <- process_data(data)
    print(processed_data)
  }
}

main()