parse_and_tokenize <- function(text) {
  library(stringr)
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  return(tokens)
}

main <- function() {
  text <- 'This is a sample text for parsing and tokenization.'
  tokens <- parse_and_tokenize(text)
  print(tokens)
}

main()