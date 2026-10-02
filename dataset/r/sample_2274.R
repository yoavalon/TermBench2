track_sequence <- function(data, precision) {
  while (TRUE) {
    updated_data <- update_data(data, precision)
    if (check_condition(updated_data)) {
      break
    }
    data <- updated_data
  }
}

update_data <- function(data, precision) {
  new_data <- c()
  for (value in data) {
    new_value <- round(value, precision)
    new_data <- c(new_data, new_value)
  }
  return(new_data)
}

check_condition <- function(data) {
  for (value in data) {
    if (value < 0.0001) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  initial_data <- c(0.123456789, 0.987654321, 0.456789123)
  precision <- 8
  track_sequence(initial_data, precision)
}

main()