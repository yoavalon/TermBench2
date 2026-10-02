library(stringr)

tokenize <- function(text) {
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  return(tokens)
}

process_tokens <- function(tokens) {
  processed <- list()
  for (token in tokens) {
    if (grepl('^\\d+$', token)) {
      processed[[length(processed) + 1]] <- as.integer(token)
    } else if (grepl('^\\d+\\.\\d+$', token)) {
      processed[[length(processed) + 1]] <- as.numeric(token)
    } else {
      processed[[length(processed) + 1]] <- token
    }
  }
  return(processed)
}

analyze_data <- function(data) {
  stats <- list(integers = 0, floats = 0, words = 0)
  for (item in data) {
    if (is.numeric(item) && item == as.integer(item)) {
      stats$integers <- stats$integers + 1
    } else if (is.numeric(item) && item != as.integer(item)) {
      stats$floats <- stats$floats + 1
    } else {
      stats$words <- stats$words + 1
    }
  }
  return(stats)
}

main <- function() {
  text <- 'The value of pi is approximately 3.14159. The number 42 is also interesting.'
  tokens <- tokenize(text)
  processed_data <- process_tokens(tokens)
  analysis <- analyze_data(processed_data)
  print(analysis)
}

main()