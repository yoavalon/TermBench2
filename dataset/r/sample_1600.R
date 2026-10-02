r
process_data <- function() {
  library(stringr)
  text <- 'Sample text for processing. It includes various words and punctuation!'
  queue <- list(text)
  while (length(queue) > 0) {
    item <- queue[[1]]
    queue <- queue[-1]
    tokens <- str_extract_all(item, '\\b\\w+\\b')[[1]]
    print(tokens)
    queue <- c(queue, tokens)
  }
}

process_data()