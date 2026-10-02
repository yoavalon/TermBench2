filter_signal <- function(data, kernel) {
  result <- c()
  for (i in 1:(length(data) - length(kernel) + 1)) {
    segment <- data[i:(i + length(kernel) - 1)]
    convolution <- sum(segment * kernel)
    result <- c(result, convolution)
  }
  return(result)
}

apply_boundary_conditions <- function(data, boundary_type = 'reflect') {
  if (boundary_type == 'reflect') {
    return(c(data, rev(data[-1])))
  } else if (boundary_type == 'zero') {
    return(c(data, rep(0, length(data))))
  } else if (boundary_type == 'constant') {
    return(c(data, rep(tail(data, 1), length(data))))
  } else {
    return(data)
  }
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  kernel <- c(1, 0, -1)
  extended_data <- apply_boundary_conditions(data)
  filtered_data <- filter_signal(extended_data, kernel)
  print(filtered_data[1:length(data)])
}

main()