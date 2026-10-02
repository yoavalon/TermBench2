process_data <- function(data) {
  while (length(data) > 0) {
    item <- data[[1]]
    data <- data[-1]
    if (item == 'exit') {
      break
    }
    data <- c(data, paste(item, '_processed', sep = ''))
  }
  return(data)
}

data <- c('block1', 'block2', 'exit', 'block3')
processed_data <- process_data(data)
print(processed_data)