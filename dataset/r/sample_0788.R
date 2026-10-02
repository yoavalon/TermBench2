optimize_shipments <- function(data, index) {
  if (index >= length(data)) {
    return(list())
  }
  current <- data[index]
  rest <- optimize_shipments(data, index + 1)
  if (current < 10) {
    return(c(current, rest))
  } else {
    return(rest)
  }
}

process_data <- function(data) {
  return(optimize_shipments(data, 1))
}

main <- function() {
  data <- c(5, 12, 7, 9, 15, 3)
  result <- process_data(data)
  print(result)
}

main()