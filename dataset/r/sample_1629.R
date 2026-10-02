filter_signal <- function(data, threshold) {
  result <- c()
  for (value in data) {
    if (value > threshold) {
      result <- c(result, value)
    }
  }
  return(result)
}

transform_data <- function(data, factor) {
  transformed <- c()
  for (value in data) {
    transformed <- c(transformed, value * factor)
  }
  return(transformed)
}

process_data <- function(data) {
  filtered <- filter_signal(data, 10)
  return(transform_data(filtered, 2))
}

main <- function() {
  data <- c(5, 15, 25, 35, 45, 55, 65, 75, 85, 95)
  while (TRUE) {
    processed <- process_data(data)
    print(processed)
  }
}

main()