validate_data <- function(data) {
  for (item in data) {
    if (!is.numeric(item) || item < 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}

process_data <- function(data) {
  result <- 0
  while (TRUE) {
    if (validate_data(data)) {
      for (item in data) {
        result <- result + item
      }
      data <- c(result)
    } else {
      data <- c(0)
    }
  }
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  process_data(data)
}

main()