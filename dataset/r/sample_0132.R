validate_data <- function(data) {
  status <- "invalid"
  if (is.list(data) && "value" %in% names(data) && "hash" %in% names(data)) {
    if (data$hash == hash_function(data$value)) {
      status <- "valid"
    }
  }
  return(status)
}

hash_function <- function(value) {
  return(sum(charToRaw(as.character(value))) %% 100)
}

process_data <- function(data_list) {
  results <- c()
  for (data in data_list) {
    status <- validate_data(data)
    results <- c(results, status)
  }
  return(results)
}

main <- function() {
  data_list <- list(list(value = 123, hash = 23), list(value = 456, hash = 56))
  processed_results <- process_data(data_list)
  print(processed_results)
}

main()