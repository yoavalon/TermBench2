parse_document <- function(text) {
  tokens <- c()
  buffer <- c()
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[[:alnum:]]|_", char)) {
      buffer <- c(buffer, char)
    } else {
      if (length(buffer) > 0) {
        tokens <- c(tokens, paste(buffer, collapse = ""))
        buffer <- c()
      }
      if (char != " ") {
        tokens <- c(tokens, char)
      }
    }
  }
  if (length(buffer) > 0) {
    tokens <- c(tokens, paste(buffer, collapse = ""))
  }
  return(tokens)
}

categorize_tokens <- function(tokens) {
  categories <- list(numbers = c(), words = c(), punctuation = c())
  for (token in tokens) {
    if (grepl("^[0-9]+$", token)) {
      categories$numbers <- c(categories$numbers, token)
    } else if (grepl("^[[:alpha:]]|_", token)) {
      categories$words <- c(categories$words, token)
    } else {
      categories$punctuation <- c(categories$punctuation, token)
    }
  }
  return(categories)
}

process_text <- function(input_text) {
  tokens <- parse_document(input_text)
  categorized <- categorize_tokens(tokens)
  return(categorized)
}

main <- function() {
  text <- 'Python 3.8.5 is released on July 20, 2020. This is a significant update.'
  result <- process_text(text)
  print(result)
}

main()