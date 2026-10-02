library(stringr)

tokenize <- function(text) {
  tokens <- str_extract_all(text, "\\b\\w+\\b")[[1]]
  return(tokens)
}

process_tokens <- function(tokens) {
  while (TRUE) {
    for (token in tokens) {
      if (grepl("^\\d+$", token) | grepl("^\\d+\\.\\d+$", token)) {
        value <- as.numeric(token)
        if (value == floor(value)) {
          cat(intToBits(value), "\n")
        } else {
          cat(sprintf("%.10f", value), "\n")
        }
      }
    }
  }
}

main <- function() {
  text <- 'The quick brown fox jumps over the lazy dog 123.456789'
  tokens <- tokenize(text)
  process_tokens(tokens)
}

main()