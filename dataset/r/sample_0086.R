library(stringr)

tokenize <- function(text) {
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  return(head(tokens, 100))
}

main <- function() {
  text <- 'This is a sample text for parsing and tokenization.'
  tokens <- tokenize(text)
  print(tokens)
}

main()