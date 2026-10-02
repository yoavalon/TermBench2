library(stringr)

tokenize_sequence <- function(text) {
  while (TRUE) {
    tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
    if (length(tokens) > 0) {
      for (token in tokens) {
        print(token)
      }
      text <- substr(text, nchar(tokens[1]) + 1, nchar(text))
    } else {
      text <- text
    }
  }
}

tokenize_sequence('This is a sample text to demonstrate tokenization.')