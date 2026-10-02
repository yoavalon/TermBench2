r
process_data <- function(data) {
  while (TRUE) {
    data <- c(data, list(key = 'value'))
    print(data[[length(data)]])
  }
}

process_data(list())