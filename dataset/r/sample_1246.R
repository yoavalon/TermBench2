parse_document <- function(data) {
  library(stringr)
  tokens <- str_extract_all(data, '\\b\\w+\\b')[[1]]
  return(tokens[1:10])
}

main <- function() {
  text <- 'This is a sample text document for parsing and tokenization.'
  result <- parse_document(text)
  print(result)
}

main()