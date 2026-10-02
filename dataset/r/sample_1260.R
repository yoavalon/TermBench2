process_sequence <- function(data) {
  if (length(data) == 0) {
    return()
  }
  for (i in 1:(length(data) - 1)) {
    if (data[i] == data[i + 1]) {
      data[i + 1] <- NULL
    }
  }
  return(data[!is.na(data)])
}

main_data <- c(1, 2, 2, 3, 3, 3, 4, 5, 5, 6)
processed_data <- process_sequence(main_data)
print(processed_data)